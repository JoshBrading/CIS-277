#include <iostream>

using namespace std;

struct Matrix {
    double a1;
    double a2;
    double b1;
    double b2;
};

void get_matrix( string &name, Matrix &m  )
{
	cout << "Enter matrix name: ";
	cin >> name;
	cout << "Enter first element of matrix: ";
	cin >> m.a1;
	cout << "Enter second element of matrix: ";
	cin >> m.a2;
	cout << "Enter third element of matrix: ";
	cin >> m.b1;
	cout << "Enter fourth element of matrix: ";
	cin >> m.b2;
}

void get_scalar( double &b )
{
        cout << "Enter scalar value: ";
        std::cin >> b;
}

void calc_sum( Matrix m1, Matrix m2, Matrix &sum )
{
        sum.a1 = m1.a1 + m2.a1;
        sum.a2 = m1.a2 + m2.a2;
        sum.b1 = m1.b1 + m2.b1;
        sum.b2 = m1.b2 + m2.b2;
}

void calc_diff( Matrix m1, Matrix m2, Matrix &diff )
{
        diff.a1 = m1.a1 - m2.a1;
        diff.a2 = m1.a2 - m2.a2;
        diff.b1 = m1.b1 - m2.b1;
        diff.b2 = m1.b2 - m2.b2;
}

void scalar_mult( double k, Matrix m, Matrix &k_m )
{
	k_m.a1 = k * m.a1;
	k_m.a2 = k * m.a2;
	k_m.b1 = k * m.b1;
	k_m.b2 = k * m.b2;
}

void calc_prod( Matrix m1, Matrix m2, Matrix &prod )
{
	prod.a1 = m1.a1 * m2.a1 + m1.a2 * m2.b1;
	prod.a2 = m1.a1 * m2.a2 + m1.a2 * m2.b2;
	prod.b1 = m1.b1 * m2.a1 + m1.b2 * m2.b1;
	prod.b2 = m1.b1 * m2.a2 + m1.b2 * m2.b2;
}

void calc_inv( Matrix m, Matrix &m_inv )
{
    	double det_a = m.a1 * m.b2 - m.b1 * m.a2;
        m_inv.a1 =  m.b2 / det_a;
        m_inv.a2 = -m.a2 / det_a;
        m_inv.b1 = -m.b1 / det_a;
        m_inv.b2 =  m.a1 / det_a;
}

void print_matrix( string name, Matrix m )
{
    cout << "\n          " << m.a1 << "  " << m.a2 << endl;
    cout << name << " = " << endl;
    cout << "          " << m.b1 << "  " << m.b2 << endl;
}

int main()
{
    Matrix m1, m2, sum, diff, k_m, k_m2, prod, m2_inv, m_inv;
    string m1_name, m2_name;
    double scalar;

    while (true)
    {
        string choice;
        cout << "Enter command: get_matrix, get_scalar, sum, diff, multiply, product, inverse, print_all." << endl;
        cin >> choice;
        if( choice == "get_matrix" )
        {
            get_matrix( m1_name, m1 );
            get_matrix( m2_name, m2 );
        }
        else if( choice == "get_scalar" )
        {
            get_scalar( scalar );
        }
        else if( choice == "sum" )
        {
            calc_sum( m1, m2, sum );
            print_matrix( "Sum", sum );
        }
        else if( choice == "diff" )
        {
            calc_diff( m1, m2, diff );
            print_matrix( "Diff", diff );
        }
        else if( choice == "multiply" )
        {
            scalar_mult( scalar, m1, k_m );
            print_matrix( "Multiply 1", k_m );

            scalar_mult( scalar, m2, k_m2 );
            print_matrix( "Multiply 2", k_m2 );
        }
        else if( choice == "product" )
        {
            calc_prod( m1, m2, prod );
            print_matrix( "Product", prod );
        }
        else if( choice == "inverse" )
        {
            calc_inv( m1, m_inv );
            print_matrix( "Inverse 1", m_inv);

            calc_inv( m2, m2_inv );
            print_matrix( "Inverse 2", m2_inv);
        }
        else if( choice == "print_all" )
        {
            print_matrix( "Sum", sum );
            print_matrix( "Diff", diff );
            print_matrix( "Multiply 1", k_m );
            print_matrix( "Multiply 2", k_m2 );
            print_matrix( "Product", prod );
            print_matrix( "Inverse 1", m_inv);
            print_matrix( "Inverse 2", m2_inv);
        }
    }
}