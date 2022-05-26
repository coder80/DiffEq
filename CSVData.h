#ifndef CSVDATA_H
#define CSVDATA_H
#include <vector>
#include <fstream>

template<typename T>
class CSVData
{
public:
    using TVec = std::vector<T>;

    CSVData(const std::string& name)
        : mName(name) {

    }

    void write(const std::pair<std::vector<TVec>, TVec>& data) {
        auto& Y = data.first;
        auto t = data.second;
        const size_t N = t.size();
        std::ofstream csvFile;
        csvFile.open(mName);
        csvFile << "t,";
        for (size_t i = 0; i < Y.size(); ++i) {
            if (i == Y.size() - 1) {
                csvFile << "Y" + std::to_string(i);
            } else {
                csvFile << "Y" + std::to_string(i) << ",";
            }
        }

        csvFile << std::endl;

        for (size_t i = 0; i < N; ++i) {
            csvFile << std::to_string(t[i]) << ",";
            for (auto& y : Y) {
                csvFile << std::to_string(y[i]) << ",";
            }

            csvFile << std::endl;
        }

        csvFile.close();
    }

private:
    std::string mName;
};

#endif // CSVDATA_H
