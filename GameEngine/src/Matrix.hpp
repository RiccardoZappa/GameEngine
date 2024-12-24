
template<typename T>
class Matrix 
{
    Matrix();
private:
    std::vector<std::vector<T>> m_Matrix_Impl;
    int rows;
    int columns;
};