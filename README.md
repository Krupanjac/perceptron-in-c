# Simple Perceptron (Linear Regression) in C

This project implements a **single-neuron perceptron** (linear regression model) from scratch in **C**, without using any machine-learning libraries.  
The goal is to demonstrate how **cost functions**, **numerical gradients**, and **finite difference** work at a low level.

## What This Program Does

The program learns a linear function of the form:

y = w * x + b

The model is trained on simple linear data:

## Training Data

| x | y |
|---|---|
| 0 | 0 |
| 1 | 5 |
| 2 | 10 |
| 3 | 15 |
| 4 | 20 |
| 5 | 25 |


The perceptron must discover this relationship by adjusting `w` (weight) and `b` (bias).

## Cost Function (Mean Squared Error)
The cost function measures how wrong the model’s predictions are:

MSE = (1/N) * Σ (y_pred − y_true)²

yaml
Copy code

Implemented in the `cost(w, b)` function.

Lower cost means better predictions.
