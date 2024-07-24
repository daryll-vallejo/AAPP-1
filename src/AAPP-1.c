#include <stdio.h>
#include <stdlib.h>
#include "AAPP.h"

int main() {
    double weights[NUM_CLASSES * MAX_FEATURES] = {0};
    double feature_min[MAX_FEATURES], feature_max[MAX_FEATURES];
    // Load the saved model
    load_model("AAPP-1.dat", weights, MAX_FEATURES);
    // Load normalization data
    load_normalization("AAPP-nomalization-1.dat", feature_min, feature_max, MAX_FEATURES);
    // Input and normalize test values
    double test_features[MAX_FEATURES];
    input_test_values(test_features, MAX_FEATURES);
    normalize_test_values(test_features, MAX_FEATURES, feature_min, feature_max);
    // Perform prediction
    double probabilities[NUM_CLASSES];
    predict_multiclass(test_features, weights, probabilities, MAX_FEATURES, NUM_CLASSES);
    // Output results
    int predicted_class = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        if (probabilities[i] > probabilities[predicted_class]) {
            predicted_class = i;
        }
    }
    printf("Predicted class: %d\n", predicted_class);
    printf("Probabilities: ");
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("%f ", probabilities[i]);
    }
    printf("\n");

    return 0;
}