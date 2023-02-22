#ifndef ARTIFICIAL_NEURAL_NETWORK
#define ARTIFICIAL_NEURAL_NETWORK

#include <vector>

#include "complexnumber.h"
#include "field_matrix.h"

class artificial_neural_network
{
public:
    long long layer_depth;
    std::vector<field_matrix<complexnumber>> weight, bias, activation, preactivation;
    std::vector<field_matrix<complexnumber>> knowledge_input_set, knowledge_output_set;
    std::vector<field_matrix<complexnumber>> del_weight, del_bias, activation, preactivation;

    artificial_neural_network();
    int fscan_brain(char *name);
    int fscan_knowledge(char *name);
    void fprint_brain(char *name);

    void forward_propagation();
    void back_propagation();
};

#endif
