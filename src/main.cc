#include "aux.hh"

int main()
{
  const size_t ROWS = 4;
  const size_t COLS = 5;
  const size_t PREC = 2;

  // Vectors

  std::vector<double> v(ROWS, 0.0e00);

  std::cout << "- Initial Vector V: " << std::endl;
  print_vector<double>(v, PREC);
  std::cout << std::endl;

  for (auto & component : v)component += 3.0e00;

  std::cout << "- New vector V: " << std::endl;
  print_vector<double>(v, PREC);
  std::cout << std::endl;

  // Martrices
  //
  // Declare permutation vector and set all its components to 0
  std::vector<int> perm(ROWS, 0);

  // Declare matrices a and a_copy and set all their components to 0.0
  std::vector<std::vector<double>>
      a(ROWS, std::vector<double>(COLS, 0.0e0)),
      a_copy(ROWS, std::vector<double>(COLS, 0.0e0));

  // Set the permutation vector p = [1,2,3,...,ROWS]
  for (size_t i = 0; i < perm.size(); ++i)
    perm[i] = i;

  // Set the values for matrix a to: a[i][j] = i+1, i = 0,...,ROWS-1,
  // j = 0,...,COLS-1
  for (size_t i = 0; i < a.size(); ++i)
    for (size_t j = 0; j < a[i].size(); ++j)
      a[i][j] = static_cast<double>(i + 1);

  a_copy = a; // Copy matrix a to matrix a_copy

  std::cout << "- Initial permutation vector p: " << std::endl;
  print_vector<int>(perm, PREC);
  std::cout << std::endl;

  std::cout << "- Initial matrix A: " << std::endl;
  print_matrix<double>(a, PREC);
  std::cout << std::endl;

  std::cout << "- Copy of matrix A: " << std::endl;
  print_matrix<double>(a_copy, PREC);
  std::cout << std::endl;

  // Switch the 1st & 4th components of permutation vector p
  std::swap(perm[0], perm[3]);

  // Switch the 1st & 4th rows of matrix a
  a[0].swap(a[3]);

  // Print the new permutation vector
  std::cout << "- New permutation vector (1st & 4th components switched): " << std::endl;
  print_vector<int>(perm, PREC);
  std::cout << std::endl;

  std::cout << "- New matrix A (1st & 4th rows switched): " << std::endl;
  print_matrix<double>(a, PREC);
  std::cout << std::endl;

  perm = {3, 2, 0, 1}; // New permutation vector
  std::cout << "- New permutation vector: " << std::endl;
  print_vector<int>(perm, PREC);
  std::cout << std::endl;

  // Permutem les files de la matriu a
  for (size_t i = 0; i < perm.size(); i++)
    a[i] = a_copy[perm[i]];

  std::cout << "- Matrix A with the files switched: " << std::endl;
  print_matrix<double>(a, PREC);
  std::cout << std::endl;

  // Deallocae permutation vector p
  std::vector<int>().swap(perm);
  std::cout << "- Deallocate pointer perm " << std::endl
            << "  Size: " << perm.size() << std::endl
            << "  Capacity: " << perm.capacity() << std::endl
            << std::endl;

  // Deallocate matrix a
  std::cout << "- Deallocate matrix a " << std::endl;
  for (auto &element : a)
  {
    std::vector<double>::iterator iter;
    std::cout << "  ";
    for (iter = element.begin(); iter < element.end(); ++iter)
      std::cout << *iter << ", ";
    std::vector<double>().swap(element);
    std::cout << "Row size: " << element.size() << ", "
              << "Row capacity: " << element.capacity() << std::endl;
  }
  std::vector<std::vector<double>>().swap(a);
  std::cout << "  Column of pointers size: " << a.size() << std::endl
            << "  Column of pointers capacity: " << a.capacity() << std::endl
            << std::endl;

  // Deallocate matrix a_copy
  std::cout << "- Deallocate matrix a_copy " << std::endl;
  for (auto &element : a_copy)
  {
    std::vector<double>::iterator iter;
    std::cout << "  ";
    for (iter = element.begin(); iter < element.end(); ++iter)
      std::cout << *iter << ", ";
    std::vector<double>().swap(element);
    std::cout << "Row size: " << element.size() << ", "
              << "Row capacity: " << element.capacity() << std::endl;
  }
  std::vector<std::vector<double>>().swap(a_copy);
  std::cout << "  Column of pointers size: " << a_copy.size() << std::endl
            << "  Column of pointers capacity: " << a_copy.capacity() << std::endl;

  return EXIT_SUCCESS;
}
