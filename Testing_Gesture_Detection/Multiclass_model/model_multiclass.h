#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float kernels[17] = { 0 };
                        float decisions[10] = { 0 };
                        int votes[5] = { 0 };
                        kernels[0] = compute_kernel(x,   -3.81  , -0.68  , 9.35  , 0.0  , 0.13  , -0.02 );
                        kernels[1] = compute_kernel(x,   -4.17  , -1.23  , 9.36  , -0.04  , 0.07  , -0.04 );
                        kernels[2] = compute_kernel(x,   4.36  , 0.48  , 9.48  , -0.01  , 0.11  , -0.02 );
                        kernels[3] = compute_kernel(x,   4.4  , 0.43  , 9.42  , -0.01  , 0.0  , -0.02 );
                        kernels[4] = compute_kernel(x,   -65.74  , 118.91  , -57.8  , -6.54  , 0.0  , 21.61 );
                        kernels[5] = compute_kernel(x,   4.44  , 0.62  , 9.44  , -0.0  , 0.1  , -0.04 );
                        kernels[6] = compute_kernel(x,   -0.05  , 7.93  , 6.31  , -0.16  , -0.19  , 0.01 );
                        kernels[7] = compute_kernel(x,   0.06  , 2.01  , 10.08  , -0.06  , 0.03  , -0.04 );
                        kernels[8] = compute_kernel(x,   0.9  , -0.17  , 10.09  , -0.05  , 0.3  , -0.0 );
                        kernels[9] = compute_kernel(x,   0.17  , 9.16  , 3.78  , -0.2  , 0.34  , 0.06 );
                        kernels[10] = compute_kernel(x,   -0.52  , -4.25  , 9.45  , 0.06  , 0.04  , -0.03 );
                        kernels[11] = compute_kernel(x,   -0.13  , -4.01  , 9.4  , -0.03  , 0.03  , -0.03 );
                        kernels[12] = compute_kernel(x,   -0.77  , -0.99  , 10.11  , 0.13  , 0.01  , -0.01 );
                        kernels[13] = compute_kernel(x,   -1.0  , 0.73  , 10.16  , -0.08  , 0.02  , -0.04 );
                        kernels[14] = compute_kernel(x,   -2.61  , -0.08  , 9.91  , -0.01  , 0.04  , -0.02 );
                        kernels[15] = compute_kernel(x,   1.2  , -0.17  , 10.02  , -0.01  , -0.14  , -0.02 );
                        kernels[16] = compute_kernel(x,   1.18  , -0.15  , 10.18  , -0.01  , 0.01  , -0.03 );
                        decisions[0] = -0.299161547253
                        + kernels[0] * 0.033387701862
                        + kernels[2] * -0.032769389013
                        + kernels[4] * -0.000618312848
                        ;
                        decisions[1] = 0.021708119507
                        + kernels[0] * 0.093011839072
                        + kernels[7] * -0.048624133162
                        + kernels[8] * -0.044387705911
                        ;
                        decisions[2] = 0.049951113171
                        + kernels[1] * 0.08903928664
                        + kernels[10] * -0.08903928664
                        ;
                        decisions[3] = 1.230276229499
                        + kernels[0] * 0.942594152599
                        + kernels[14] * -0.942594152599
                        ;
                        decisions[4] = -2.501979576356
                        + kernels[2]
                        + kernels[4] * 0.075422986884
                        + kernels[5] * 0.357722243592
                        + kernels[6] * -0.336686769029
                        + kernels[8] * -0.336918893784
                        + kernels[9] * -0.759539567663
                        ;
                        decisions[5] = -0.094991289103
                        + kernels[3] * 0.049706362638
                        + kernels[11] * -0.049706362638
                        ;
                        decisions[6] = 0.027795061001
                        + kernels[2] * 0.193789529769
                        + kernels[4] * 0.000878747919
                        + kernels[15] * -0.194668277688
                        ;
                        decisions[7] = 0.105167275926
                        + kernels[8] * 0.122273341821
                        + kernels[11] * -0.122273341821
                        ;
                        decisions[8] = 0.156326894741
                        + kernels[7] * 0.864938456208
                        + kernels[8]
                        + kernels[13] * -0.795444860127
                        + kernels[15] * -0.069493596081
                        - kernels[16]
                        ;
                        decisions[9] = -0.065354722699
                        + kernels[11] * 0.198797266503
                        + kernels[12] * -0.198797266503
                        ;
                        votes[decisions[0] > 0 ? 0 : 1] += 1;
                        votes[decisions[1] > 0 ? 0 : 2] += 1;
                        votes[decisions[2] > 0 ? 0 : 3] += 1;
                        votes[decisions[3] > 0 ? 0 : 4] += 1;
                        votes[decisions[4] > 0 ? 1 : 2] += 1;
                        votes[decisions[5] > 0 ? 1 : 3] += 1;
                        votes[decisions[6] > 0 ? 1 : 4] += 1;
                        votes[decisions[7] > 0 ? 2 : 3] += 1;
                        votes[decisions[8] > 0 ? 2 : 4] += 1;
                        votes[decisions[9] > 0 ? 3 : 4] += 1;
                        int val = votes[0];
                        int idx = 0;

                        for (int i = 1; i < 5; i++) {
                            if (votes[i] > val) {
                                val = votes[i];
                                idx = i;
                            }
                        }

                        return idx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Back";
                            case 1:
                            return "Front";
                            case 2:
                            return "Left";
                            case 3:
                            return "Right";
                            case 4:
                            return "Stable";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: linear
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 6);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 6; i++) {
                            kernel += x[i] * va_arg(w, double);
                        }

                        return kernel;
                    }
                };
            }
        }
    }