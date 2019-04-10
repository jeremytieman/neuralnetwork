#include <vector>

namespace CodexMachina::NeuralNetwork
{
  template<typename T>
  class Tensor
  {
  public:
    Tensor(std::vector<std::size_t> dims, std::vector<T> data) : _dims(dims), _data(data)
    {
      for (std::size_t i = 0; i < _dims.size(); ++i)
      {
        (i == 0) ? _strides.push_back(1) : _strides.push_back(_dims[i - 1] * _strides[i - 1]);
      }
    }

    std::vector<T>& Data() const { return _data; }
    std::vector<std::size_t>& Dimensions() const { return _dims; }
    std::size_t Rank() const { return _dims.size(); }
  private:
    std::vector<T> _data;
    std::vector<size_t> _dims;
    std::vector<size_t> _strides;
  };
}