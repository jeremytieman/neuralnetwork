#include "Tensor.h"

namespace CodexMachina::NeuralNetwork
{
  template<class T>
  class AddOper
  {
    Tensor<T> process(const Tensor<T>& input1, const Tensor<T>& input2);
  };
}