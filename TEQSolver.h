#ifndef TEQSOLVER_H
#define TEQSOLVER_H

#include <vector>

template<typename T>
//!
//! \Euler method solver diff eq class
//!
class TEQSolver
{
public:
    using TVec = std::vector<T>;
    TEQSolver(const TVec& X0, T a, T b)
        : mX0(X0), mA(a), mB(b) {

    }

    //!
    //! \brief solve equation
    //! \return pair (Y, t)
    //!
    std::pair<std::vector<TVec>, TVec> solve() {
        std::pair<std::vector<TVec>, TVec> result;
        const size_t N = 1000; //Points
        T h = (mB - mA) / (N - 1); // step

        auto& Y = result.first;
        auto& tArray = result.second;

        Y.resize(5);
        tArray.resize(N);

        for (auto& e : Y) {
            e.resize(N);
        }

        //Begining values
        Y[0][0] = mX0[0];
        Y[1][0] = mX0[1];
        Y[2][0] = mX0[2];
        Y[3][0] = mX0[3];
        Y[4][0] = mX0[4];

        //Main loop of Euler method
        for (size_t t = 0; t < N - 1; ++t) {
            Y[0][t + 1] = Y[0][t] + Y[1][t] * h;
            Y[1][t + 1] = Y[1][t] + Y[2][t] * h;
            Y[2][t + 1] = Y[2][t] + Y[3][t] * h;
            Y[3][t + 1] = Y[3][t] + Y[4][t] * h;
            Y[4][t + 1] = Y[4][t] - (15 * Y[4][t] + 90 * Y[3][t] + 270 * Y[2][t] + 405 * Y[1][t]) * h;
            tArray[t + 1] = tArray[t] + h;
        }

        return result;
    }

    ~TEQSolver() = default;

private:
    TVec mX0;
    T mA;
    T mB;
};

#endif // TEQSOLVER_H
