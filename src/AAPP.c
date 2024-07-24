#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "AAPP.h"

void load_model(const char *filename, double weights[], int num_features) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file for loading model");
        exit(EXIT_FAILURE);
    }
    fread(weights, sizeof(double), num_features * NUM_CLASSES, file);
    fclose(file);
}

void input_test_values(double features[], int num_features) {
    printf("Enter test values for %d features:\n", num_features);
    for (int i = 0; i < num_features; i++) {
        printf("Feature %d: ", i + 1);
        scanf("%lf", &features[i]);
    }
}

void load_normalization(const char *filename, double feature_min[], double feature_max[], int num_features) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file for loading normalization values");
        exit(EXIT_FAILURE);
    }
    fread(feature_min, sizeof(double), num_features, file);
    fread(feature_max, sizeof(double), num_features, file);
    fclose(file);
}

void normalize_test_values(double features[], int num_features, double feature_min[], double feature_max[]) {
    for (int i = 0; i < num_features; i++) {
        features[i] = (features[i] - feature_min[i]) / (feature_max[i] - feature_min[i]);
    }
}

void softmax(double z[], double result[], int num_classes) {
    double max = z[0];
    for (int i = 1; i < num_classes; i++) {
        if (z[i] > max) max = z[i];
    }
    double sum = 0.0;
    for (int i = 0; i < num_classes; i++) {
        result[i] = exp(z[i] - max);
        sum += result[i];
    }
    for (int i = 0; i < num_classes; i++) {
        result[i] /= sum;
    }
}

void predict_multiclass(double features[], double weights[], double *probabilities, int num_features, int num_classes) {
    double z[num_classes];
    for (int c = 0; c < num_classes; c++) {
        z[c] = 0.0;
        for (int i = 0; i < num_features; i++) {
            z[c] += features[i] * weights[c * num_features + i];
        }
    }
    softmax(z, probabilities, num_classes);
}