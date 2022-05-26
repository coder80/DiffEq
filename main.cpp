#include <iostream>
#include "TEQSolver.h"
#include "CSVData.h"

using namespace std;

int main()
{
    TEQSolver<float> s({0.f, 3.f, -9.f, -8.f, 0.f}, 0.f, 5.f);
    auto result = s.solve();
    CSVData<float> data("out.csv");
    data.write(result);
    return 0;
}
