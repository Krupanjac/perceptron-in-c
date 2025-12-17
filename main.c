#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rand_float() ((float)rand() / (float)RAND_MAX)


float train_data[][2] = {
    {0.0, 0.0},
    {1.0, 5.0},
    {2.0, 10.0},
    {3.0, 15.0},
    {4.0, 20.0},
    {5.0, 25.0},
};

#define train_data_size (sizeof(train_data) / sizeof(train_data[0]))


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float cost(float w, float b) {
    float result = 0.0f;
    for (size_t i = 0; i < train_data_size; ++i) {
        float x = train_data[i][0];
        float y = x * w + b;
        float d = y - train_data[i][1];
        result += d * d;
    }
    return result / (float)train_data_size; // Mean Squared Error
}


//y = x*w
int main () {

    srand(69); // Seed for reproducibility
    float w = rand_float() * 10.0f; // Random initial weight between 0 and 10
    float bias = rand_float() * 5.0f; // Random initial bias between 0 and 10

    printf("Initial weight: %f, bias: %f\n", w, bias);

    float eps = 1e-3f;
    float rate = 1e-3f;

    printf("%f\n", cost(w, bias));
    for(size_t i=0;i<10000;++i)
    {
    float c = cost(w, bias);
    float dw = (cost(w + eps, bias) - c) / eps;
    float db = (cost(w, bias + eps) - c) / eps;
    w-=rate*dw;
    bias-=rate*db;
    printf("cost : %f, w: %f, b: %f\n", cost(w, bias), w, bias);

    //printf("%f\n", cost(w));
    }
    printf("------------\n");
    printf("w=%f, b=%f\n", w, bias);

    return 0;
}