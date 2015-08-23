//Language: GNU C++11


// 567D_ships.cc - Codeforces.com 567D Ships program by Sergey 2015

#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Unit tests base Class
///////////////////////////////////////////////////////////////////////////////


class Unittest { public:
    #define CHECK(a,b)  check<long long>(a, b, #a, #b, __FILE__, __LINE__, __FUNCTION__);
    #define CHECKT(a)   check<int>(a, 1, #a, "true", __FILE__, __LINE__, __FUNCTION__);
    #define CHECKS(a,b) check<cs>(a, b, #a, #b, __FILE__, __LINE__, __FUNCTION__);
    typedef const string& cs;
    int checks, fails; ostringstream serr; istringstream *in;
    Unittest() { checks = fails = 0;}
    run() { streambuf* ocin = cin.rdbuf(); test_list(); cin.rdbuf(ocin); return status(); }
    virtual test_list() { single_test(); }
    virtual single_test() {}
    test_cin(cs s){ in = new istringstream(s); cin.rdbuf(in->rdbuf()); }
    template <typename T> check(T a, T b, cs stra, cs strb, cs file, int line, cs func) {
        checks++; if (a == b) { cout << "."; return 0; } 
        fails++; cout << "F"; hdr(stra, strb, file, line, func);
        serr << "  Error: \"" << a << "\" ! = \"" << b << "\"" << endl << endl;
    }
    hdr(cs stra, cs strb, cs file, int line, cs func) {
        serr << "==================================================" << endl;
        serr << "FAIL: " << func << endl;
        serr << "--------------------------------------------------" << endl;
        serr << "File \"" << file << "\", line " << line << " in " << func << endl;
        serr << "  Checking " << stra << " == " << strb << endl;
    }
    status() {
        cout << endl; if (fails) cout << serr.str();
        cout << "--------------------------------------------------" << endl;
        cout << "Ran " << checks << " checks in " << dclock() << "s" << endl << endl;
        if (fails) cout << "FAILED (failures=" << fails << ")"; else cout << "OK" << endl;
        return fails > 0;
    }
    double dclock() { return double(clock()) / CLOCKS_PER_SEC; }
};

///////////////////////////////////////////////////////////////////////////////
// Ships Class (Main Program)
///////////////////////////////////////////////////////////////////////////////

class Ships { public:

    static int const N = 200002;

    int n, k, a, m;
    long long nums[N];

    set <int> field;
    int max;

    Ships(){

        // Decoding input max sizes
        cin >> n >> k >> a >> m;

        // Decoding input list
        for(int i = 0; i < m; i++) cin >> nums[i];

        field.insert(n + 1);
        field.insert(0);

        max = num_ships(0, n + 1, a);
    }

    num_ships(int a, int b, int size){
        if (a < b) swap(a, b);
        int len = abs(a - b - 1);
        int result = len / (size + 1);
        int rem = len % (size + 1);
        if (rem == size) result++;
        return result;
    }

    step(int x) {
        auto ilb = field.lower_bound(x);
        int lb = *ilb;
        int pr = *(--ilb);
        max -= num_ships(lb, pr, a);
        max += num_ships(pr, x, a) + num_ships(lb, x, a);
        field.insert(x);
    }

    string calculate(){

        long long result = -1;

        for (int i = 0; i < m; i++) {

            step(nums[i]);
            if (max < k) { result = i + 1; break; }
        }

        ostringstream resstr;
        resstr << result;

        return resstr.str();
    }
};



///////////////////////////////////////////////////////////////////////////////
// Local Unit tests
///////////////////////////////////////////////////////////////////////////////


class LocalUnittest: public Unittest {

    Ships* d;

    single_test() {

        // Constructor test
        string test = "11 3 3\n5\n4 8 6 1 11";
        test_cin(test);
        d = new Ships;
        CHECK(d->n, 11);
        CHECK(d->m, 5);
        CHECK(d->nums[0], 4);

        CHECK(d->max, 3);
        d->step(4);
        CHECK(d->max, 3);
        d->step(8);
        CHECK(d->max, 3);

        CHECK(d->num_ships(0, 1, 2), 0)
        CHECK(d->num_ships(0, 2, 2), 0)
        CHECK(d->num_ships(0, 3, 2), 1)
        CHECK(d->num_ships(0, 4, 2), 1)
        CHECK(d->num_ships(0, 5, 2), 1)
        CHECK(d->num_ships(0, 6, 2), 2)

        // Sample test
        test_cin(test);
        CHECKS((new Ships)->calculate(), "3");

        // Sample test
        test_cin("5 1 3\n2\n1 5");
        CHECKS((new Ships)->calculate(), "-1");

        // Sample test
        test_cin("5 1 3\n1\n3");
        CHECKS((new Ships)->calculate(), "1");

        // My test
        test_cin("5000 1660 2\n20\n"
        "1 100 18 102 300 81 19 25 44 88 1337 4999 1054 1203 91 16 164 914 1419 1487");
        CHECKS((new Ships)->calculate(), "18");

        // Time limit test
        // time_limit_test(10000);
    }

    time_limit_test(int nmax){

        int smax = nmax;
        ostringstream stest;
        
        // Random inputs
        stest << nmax << " " << smax << endl;
        for(int i = 0; i < nmax; i++) stest << i << " " << i+1 << endl;
        for(int i = 0; i < smax; i++) stest << i * 5 % 40 << " ";

        // Run the test
        double start = dclock();
        test_cin(stest.str());
        d = new Ships;
        double calc = dclock();
        d->calculate();
        double stop = dclock();
        cout << endl << "Timelimit Test: " << stop - start << "s (init ";
        cout << calc - start << "s calc " << stop - calc << "s)" << endl;
    }
};

///////////////////////////////////////////////////////////////////////////////
// Main Execution
///////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[]) {

    // Faster cin and cout
    ios_base::sync_with_stdio(0);cin.tie(0);

    if (argc > 1 && !strcmp(argv[1], "-ut")) {
        LocalUnittest lut;
        return lut.run();
    }
    cout << (new Ships)->calculate() << endl;
    return 0;
}

