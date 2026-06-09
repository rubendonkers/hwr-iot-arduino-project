# Knowledge Distillation Project

This project demonstrates the process of **Knowledge Distillation**, a technique used to transfer the knowledge from a large, pre-trained "Teacher" model to a smaller, more efficient "Student" model. By training the Student to mimic the output probability distributions (soft targets) of the Teacher, we create a compact model that retains much of the Teacher's performance.

## Project Structure
- `StudentTeacher.py`: Contains the `StudentTeacherTrainer` class, which handles the distillation logic, including the calculation of the distillation loss using temperature-scaled softmax.
- `notebook.ipynb` (or similar script): The main execution file that sets up the environment, seeds the random number generators, selects the hardware (GPU/CPU), and initializes the training process.

## Key Components

### 1. Hardware Acceleration
The project utilizes PyTorch to automatically detect and utilize a GPU (like the NVIDIA T4) if available. The use of a GPU is essential for accelerating the high-volume matrix multiplication tasks inherent in neural network training.

### 2. Random Seed Fixing
To ensure reproducibility of results, random seeds are fixed across `torch`, `numpy`, and `tensorflow`. This ensures that experiments can be replicated and compared fairly.

### 3. Knowledge Distillation Process
The core of the project involves a combined loss function:
- **Distillation Loss:** Minimizes the difference between the Student's and Teacher's probability distributions using a temperature ($T$) parameter to "soften" the output, revealing the "dark knowledge" or nuanced relationships between classes.
- **Task Loss:** Ensures the Student also learns to predict the ground-truth labels.

## Prerequisites
- Python 3.x
- PyTorch
- Hugging Face `transformers`
- Scikit-learn
- NumPy

## How it works
1. **Model Initialization:** A large pre-trained Teacher model (e.g., RoBERTa) and a smaller Student model (e.g., ALBERT) are loaded.
2. **Setup:** The environment is configured to use the fastest available hardware.
3. **Training:** The `StudentTeacherTrainer` iterates through the dataset, passing inputs through both the Teacher and Student. The loss is computed by comparing the Student's output to both the hard labels and the Teacher's soft, temperature-adjusted logits.
4. **Optimization:** The Student's parameters are updated to minimize the combined loss.

## License
This project is for educational purposes regarding model compression and efficient AI development.