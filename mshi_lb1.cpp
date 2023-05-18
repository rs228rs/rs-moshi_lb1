#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Функція для оцінки розв’язку
int findr( const vector<int>& x ) {
    int r = 0;
    int n  = x.size();

    for ( int i = 0; i < n ; i++ ) {
        for ( int j = i + 1; j < n ; j++ ) {
            if ( x[i] == x[j] || abs( x[i] - x[j]) == j - i ) {
                r++;
            }
        }
    }

    return r;
}

// Функція початкової ініціалізації
vector<int> generatex( int n ) {
    vector<int> x( n );

    for ( int i = 0; i < n ; i++ ) {
        x[i] = rand() % n ;
    }



    return x;
}

// Функція випадкової зміни розв’язку і безпосередня реалізація алгоритму відпалу
vector<int> f( int n , double max_t, double minus_t, int max_it ) {

    srand( static_cast<unsigned int>( time( 0 ) ) );

    vector<int> x = generatex( n );
    int r = findr( x );

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[j] == i) {
                cout << " " << x[j];
            }
            else {
                cout << " " << x[j];
            }
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[j] == i) {
                cout << " 1";
            }
            else {
                cout << " .";
            }
        }
        cout << endl;
    }

    cout << endl;

    vector<int> best_x = x;
    int best_r = r;

    double t = max_t;

    for ( int it = 0; it < max_it; it++ ) {

        vector<int> new_x = x;
        int a = rand() % n ;
        int b = rand() % n ;
        new_x[a] = b;

        int new_r = findr(new_x);

        if (new_r < r || exp(( r - new_r ) / t ) > static_cast<double>( rand()) / RAND_MAX ) {
            x = new_x;
            r = new_r;
        }

        if (r < best_r) {
            best_x = x;
            best_r = r;
        }

        t *= minus_t;
    }

    return best_x;
}

// Функція виводу результату на екран у вигляді шахової дошки
void coutx( const vector<int>& x ) {
    int n = x.size();

    for ( int i = 0; i < n ; i++ ) {
        for ( int j = 0; j < n ; j++ ) {
            if ( x[j] == i ) {
                cout << " 1";
            }
            else {
                cout << " .";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void coutx_raw(const vector<int>& x) {
    int n = x.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[j] == i) {
                cout << " " << x[j];
            }
            else {
                cout << " " << x[j];
            }
        }
        cout << endl;
    }

    cout << endl;
}

int main() {
    int n = 16;
    double max_t = 1000.0;
    double minus_t = 0.99;
    int max_it = 10000;

    vector<int> x = f( n, max_t, minus_t, max_it );

    coutx_raw(x);
    coutx(x);

    return 0;
}
