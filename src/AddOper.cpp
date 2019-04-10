#include "AddOper.h"
#include <stdexcept>
#include <sstream>

namespace CodexMachina::NeuralNetwork
{
  template<class T>
  Tensor<T> AddOper<T>::process(const Tensor<T>& input1, const Tensor<T>& input2)
  {
    if (input1.Rank() != input2.Rank())
    {
      std::stringstream ss{ "Ranks of inputs do not match. Input1 rank: " };
      ss << input1.Rank() << " Input2 rank: " << input2.Rank() << "\n";
      throw std::invalid_argument(ss.str());
    }

    {
      const auto& dims1 = input1.Dimensions();
      const auto& dims2 = input2.Dimensions();

      for (std::size_t i = 0; i < input1.Rank(); ++i)
      {
        if (dims1[i] != dims2[i])
        {
          std::stringstream ss{ "Dimensions at index " };
          ss << i << " do not match. Dimension 1: " << dims1[i];
          ss << " Dimension 2: " << dims2[i] << "\n";
          throw std::invalid_argument(ss.str());
        }
      }
    }
  }
}