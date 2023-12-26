#include "aux.hh"

int main()
{
    const size_t ROWS = 4;
    const size_t COLS = 5;
    const size_t PREC = 2;

    // Declare permutation vector and set all its components to 0
    std::vector<int> p(ROWS,0);                       

    // Declare matrices a and aa and set all their components to 0.0
    std::vector<std::vector<double> > 
	    a(ROWS, std::vector<double>(COLS, 0.0e0)), 
           aa(ROWS, std::vector<double>(COLS, 0.0e0));

    // Set the permutation vector p = [1,2,3,...,ROWS] 
    for (size_t i = 0; i < p.size(); ++i) p[i]=i; 

    // Set the values for matrix a to: a[i][j] = i+1, i = 0,...,ROWS-1,
    // j = 0,...,COLS-1
    for (size_t i = 0; i < a.size(); ++i)
	    for (size_t j = 0; j < a[i].size(); ++j)
		    a[i][j] = static_cast<double>(i+1);

    aa = a; // Copy matrix a to matrix aa

    std::cout << "- Initial permutation vector p: " << std::endl; 
    print_vector<int>(p,PREC); std::cout << std::endl;

    std::cout << "- Initial matrix A: " << std::endl; 
    print_matrix<double>(a,PREC); std::cout << std::endl;  

    std::cout << "- Copy of matrix A: " << std::endl; 
    print_matrix<double>(aa,PREC); std::cout << std::endl; 

    // Switch the 1st & 4th components of permutation vector p
    std::swap(p[0], p[3]);

    // Switch the 1st & 4th rows of matrix a
    a[0].swap(a[3]);

    // Print the new permutation vector 
    std::cout << "- New permutation vector (1st & 4th components switched): " << std::endl; 
    print_vector<int>(p, PREC); std::cout << std::endl;

    std::cout << "- New matrix A (1st & 4th rows switched): " << std::endl;
    print_matrix<double>(a, PREC); std::cout << std::endl;

    p = { 3,2,0,1 }; // New permutation vector
    std::cout << "- New permutation vector: " << std::endl;
    print_vector<int>(p, PREC); std::cout << std::endl;

    //Permutem les files de la matriu a
    for (size_t i=0; i < p.size(); i++) a[i] = aa[p[i]];

    std::cout << "- Matrix A with the files switched: " << std::endl;
    print_matrix<double>(a, PREC); std::cout << std::endl;

    // Deallocae permutation vector p
    std::vector<int>().swap(p);
    std::cout << "- Deallocate pointer p " << std::endl
    << "  Size: " << p.size() << std::endl
    << "  Capacity: " << p.capacity() << std::endl << std::endl;

    // Deallocate matrix a
    std::cout << "- Deallocate matrix a " << std::endl;
    for (auto & element : a) {
      std::vector<double>::iterator iter; 
      std::cout << "  ";
      for (iter = element.begin(); iter < element.end(); ++iter) std::cout << *iter << ", ";
      std::vector<double>().swap(element);
      std::cout << "Row size: " << element.size() << ", "
        << "Row capacity: " << element.capacity() << std::endl;
    }
    std::vector<std::vector<double> >().swap(a);
    std::cout << "  Column of pointers size: " << a.size() << std::endl
    << "  Column of pointers capacity: " << a.capacity() << std::endl << std::endl;
    
    // Deallocate matrix aa
    std::cout << "- Deallocate matrix aa " << std::endl;
    for (auto & element : aa) {
      std::vector<double>::iterator iter;
      std::cout << "  ";
      for (iter = element.begin(); iter < element.end(); ++iter) std::cout << *iter << ", ";
      std::vector<double>().swap(element);
      std::cout << "Row size: " << element.size() << ", "
        << "Row capacity: " << element.capacity() << std::endl;
    }
    std::vector<std::vector<double> >().swap(aa);
    std::cout << "  Column of pointers size: " << aa.size() << std::endl
    << "  Column of pointers capacity: " << aa.capacity() << std::endl;

    return EXIT_SUCCESS;
}

