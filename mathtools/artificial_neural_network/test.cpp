#include <string>
#include "artificial_neural_network.h"

artificial_neural_network AA;
std::string name = "brain_before_";
std::string namen = "new_";
std::string mname = "mnist_small_";
std::string mnamen = "mnist_";

int main()
{
    AA.fscan_knowledge(mnamen.c_str());
    AA.fscan_brain(mname.c_str());
    AA.self_realer();
    for (int i = 1; i <= 10; i++)
    {
        AA.forward_propagation(AA.knowledge_input_set[i]).print();
        AA.knowledge_output_set[i].print();
        printf("fp\n");
    }
    for (int i = 1; i <= 0; i++)
    {
        // AA.back_propagation_chop(((i - 1) % 120) * 500, 500).print();
        AA.back_propagation_chop(((i + 260) % 600) * 100 + 1, 100).print();
        // AA.back_propagation().print();
        AA.self_realer();
        printf("%6d\n", i);
        // printf("bp\n");
    }
    AA.fprint_brain(mname.c_str());
    return 0;
}
