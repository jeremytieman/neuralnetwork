#include "AddOper.h"
#include <stdexcept>
#include <sstream>

namespace CodexMachina::NeuralNetwork
{
  template<class T>
  Tensor<T> AddOper<T>::process(const Tensor<T>& input1, const Tensor<T>& input2)
  {
    {
      const auto& dims1 = input1.Dimensions();
      const auto& dims2 = input2.Dimensions();
      if (dims1 != dims2) throw std::invalid_argument("Dimensions of inputs do not match.");
    }

    const auto& outputDims = input1.Dimensions();
    const auto& inputData1 = input1.Data();
    const auto& inputData2 = input2.Data();
    std::vector<T> outputData;
    outputData.reserve(inputData1.size());
    for (std::size_t i = 0; i < inputData1.size(); ++i)
      outputData.push_back(inputData1[i] + inputData2[i]);
    return Tensor<T>(outputDims, outputData);
  }
}
