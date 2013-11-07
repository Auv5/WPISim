#include "Log.hpp"

int main()
{
    Log *l = new Log();

    l->Filter(-1);

    l->Debug("Test");
}
