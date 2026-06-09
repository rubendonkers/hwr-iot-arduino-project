#include <Arduino.h>
#include <Wire.h> 
#include <grove_two_rgb_led_matrix.h> 
#include <test-arduino-movement-lamp_inferencing.h>
#include <Arduino_LSM9DS1.h>

// DIT IS DE FIX VOOR DE RANDOM NUMMERS
#define CONVERT_G_TO_MS2 9.80665f

GroveTwoRGBLedMatrixClass matrix;
static bool debug_nn = false;

void setup() {
    Serial.begin(115200);
    while (!Serial);

    // I2C starten
    Wire.begin();

    if (!IMU.begin()) {
        Serial.println("Failed to initialize IMU!");
    }

    // Geef de matrix stroom en tijd om wakker te worden
    delay(500); 
    matrix.displayColorBlock(0x000000, 0, true); // Matrix op zwart/uit zetten
}

void loop() {
    float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE] = { 0 };

    // Verzamel data
    for (size_t ix = 0; ix < EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE; ix += 3) {
        uint64_t next_tick = micros() + (EI_CLASSIFIER_INTERVAL_MS * 1000);
        IMU.readAcceleration(buffer[ix], buffer[ix + 1], buffer[ix + 2]);
        
        // DE WISKUNDIGE FIX: Zet G-kracht om naar m/s2
        buffer[ix + 0] *= CONVERT_G_TO_MS2;
        buffer[ix + 1] *= CONVERT_G_TO_MS2;
        buffer[ix + 2] *= CONVERT_G_TO_MS2;

        // Wacht exact lang genoeg voor de volgende meting
        if (next_tick > micros()) {
            delayMicroseconds(next_tick - micros());
        }
    }

    signal_t signal;
    numpy::signal_from_buffer(buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);
    
    ei_impulse_result_t result = { 0 };
    run_classifier(&signal, &result, debug_nn);

    // Print de percentages
    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        ei_printf("%s: %.2f | ", result.classification[ix].label, result.classification[ix].value);
    }
    ei_printf("\n");

    // ==========================================
    // LOGICA VOOR DE LED MATRIX
    // ==========================================
    // 0xFF0000 = Rood, 0x00FF00 = Groen, 0x000000 = Uit
    // Tijd staat op 2000 milliseconden (2 seconden) kleur laten zien
    
    if (result.classification[0].value > 0.90) { 
        ei_printf(">>> FAST DETECTED (Rood)\n");
        matrix.displayColorBlock(0xFF0000, 2000, true); 
    } 
    else if (result.classification[2].value > 0.90) { 
        ei_printf(">>> SLOW DETECTED (Groen)\n");
        matrix.displayColorBlock(0x00FF00, 2000, true); 
    } 
    else { 
        // Niets -> Uit
        matrix.displayColorBlock(0x000000, 100, true);
    }
    
    delay(100); 
}