#ifndef AAPP_H
#define AAPP_H

#define MAX_LINE_LENGTH 1024
#define MAX_FEATURES 3
#define NUM_CLASSES 4

void load_model(const char *filename, double weights[], int num_features);
void input_test_values(double features[], int num_features);
void load_normalization(const char *filename, double feature_min[], double feature_max[], int num_features);
void normalize_test_values(double features[], int num_features, double feature_min[], double feature_max[]);
void softmax(double z[], double result[], int num_classes);
void predict_multiclass(double features[], double weights[], double *probabilities, int num_features, int num_classes);

#endif 