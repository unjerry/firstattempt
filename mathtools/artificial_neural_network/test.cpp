#include <string>
#include "artificial_neural_network.h"

artificial_neural_network AA;
std::string name = "brain_before_";
std::string namen = "new_";

int main()
{
    AA.fscan_knowledge(name.c_str());
    AA.fscan_brain(name.c_str());
    for (int i = 1; i <= AA.knowledge_set_size; i++)
    {
        AA.forward_propagation(AA.knowledge_input_set[i]).print();
    }
    for (int i = 1; i <= 1; i++)
    {
        AA.back_propagation().print();
        printf("%d\n", i);
    }
    AA.fprint_brain(name.c_str());
    return 0;
}
