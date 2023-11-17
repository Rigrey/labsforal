#include <iostream>
#include <string>

struct Matrix {
  int** data_ = nullptr;
  size_t n_ = 0u;  // столбцы
  size_t m_ = 0u;  // строки
  size_t size() { return this->n_ * this->m_; }

  void find(const int& f_) {
    size_t n = find_n(f_);
    if (n != this->n_ + 1) {
      std::string ns;
      ns.push_back(n);
      std::string ms;
      ms.push_back(find_m(f_));
      std::cout << "N is: " << ns << ". M is: " << ms << std::endl;
      return;
    }
    std::cout << "Not Found!" << std::endl;
  }

  void print() {
    for (size_t i = 0; i < this->n_; ++i) {
      std::cout << "| ";
      for (size_t j = 0; j < this->m_; ++j) {
        std::cout << this->data_[i][j] << ' ';
      }
      std::cout << "|" << std::endl;
    }
  }

 private:
  size_t find_n(const int& f_) {
    for (size_t i = 0; i < this->n_; ++i) {
      for (size_t j = 0; j < this->m_; ++j) {
        if (this->data_[i][j] == f_) {
          return i;
        }
      }
    }
    return this->n_ + 1;
  }
};

void Construct(Matrix& out, size_t n, size_t m) {
  out.n_ = n;
  out.m_ = m;
  out.data_ = new int*[n];
  for (size_t i = 0; i < n; ++i) {
    out.data_[i] = new int[m];
    for (size_t j = 0; j < m; ++j) {
      out.data_[i][j] = 0;
    }
  }
}

void Destruct(Matrix& in) {
  for (size_t i = 0; i < in.n_; ++i) {
    delete[] in.data_[i];
  }
  delete[] in.data_;
  in.data_ = nullptr;
}

Matrix Copy(const Matrix& matrix) {
  Matrix mat;
  Construct(mat, matrix.n_, matrix.m_);
  for (size_t i = 0; i < mat.n_; ++i) {
    for (size_t j = 0; j < mat.m_; ++j) {
      mat.data_[i][j] = matrix.data_[i][j];
    }
  }
  return mat;
}

Matrix Add(const Matrix& a, const Matrix& b) {
  if ((a.n_ == b.n_) && (a.m_ == b.m_)) {
    Matrix summ;
    Construct(summ, a.n_, a.m_);
    for (size_t i = 0; i < summ.n_; ++i) {
      for (size_t j = 0; j < summ.m_; ++j) {
        summ.data_[i][j] = a.data_[i][j] + b.data_[i][j];
      }
    }
    return summ;
  }
  return Matrix();
}

Matrix Sub(const Matrix& a, const Matrix& b) {
  if ((a.n_ == b.n_) && (a.m_ == b.m_)) {
    Matrix subb;
    Construct(subb, a.n_, a.m_);
    for (size_t i = 0; i < subb.n_; ++i) {
      for (size_t j = 0; j < subb.m_; ++j) {
        subb.data_[i][j] = a.data_[i][j] - b.data_[i][j];
      }
    }
    return subb;
  }
  return Matrix();
}

Matrix Mult(const Matrix& a, const Matrix& b) {
  if (a.m_ == b.n_) {
    Matrix mult;
    Construct(mult, a.n_, b.m_);
    for (size_t i = 0; i < mult.n_; ++i) {
      for (size_t j = 0; j < mult.m_; ++j) {
        for (size_t k = 0; k < a.m_; ++k) {
          mult.data_[i][j] += a.data_[i][k] * b.data_[k][j];
        }
      }
    }
    return mult;
  }
  return Matrix();
}

void Transposition(Matrix& matrix) {
  Matrix temp;
  Construct(temp, matrix.m_, matrix.n_);
  for (size_t i = 0; i < temp.n_; ++i) {
    for (size_t j = 0; j < temp.m_; ++j) {
      temp.data_[i][j] = matrix.data_[j][i];
    }
  }
  Destruct(matrix);
  matrix = temp;
}

bool operator==(const Matrix& a, const Matrix& b) {
  if ((a.n_ == b.n_) && (a.m_ == b.m_)) {
    for (size_t i = 0; i < a.n_; ++i) {
      for (size_t j = 0; j < a.m_; ++j) {
        if (a.data_[i][j] != b.data_[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}


int main() {
  return 0;
}
