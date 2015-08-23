//Language: GNU C++11


#include <bits/stdc++.h>

using Int = long long unsigned;

const unsigned MAX_POS = 76;
const unsigned MAX_CONSTRAINTS = 101;


unsigned n;
Int dp[MAX_POS][MAX_POS];
bool seen[MAX_POS][MAX_POS];

std::tuple<unsigned,std::string,unsigned> constraints[MAX_CONSTRAINTS];

bool check_constraints_end ( unsigned l , unsigned r ) {
    for ( auto& c : constraints ) {
        unsigned x {std::get<0>(c)};
        std::string s {std::get<1>(c)};
        unsigned y {std::get<2>(c)};
        
        if ( y == l || y == r ) {
            std::swap(x, y);
            if ( s[0] == '<' ) {
                s[0] = '>';
            }
            else if ( s[0] == '>' ) {
                s[0] = '<';
            }
        }

        if ( (x == l || x == r) && (s == "<" || s == ">") && (y == l || y == r) ) {
            return false;   
        }
    }

    return true;
}
bool check_constraints ( unsigned gt_fr , unsigned gt_to , unsigned l , unsigned r ) {
    for ( auto& c : constraints ) {
        unsigned x {std::get<0>(c)};
        std::string s {std::get<1>(c)};
        unsigned y {std::get<2>(c)};
        
        if ( y == l || y == r ) {
            std::swap(x, y);
            if ( s[0] == '<' ) {
                s[0] = '>';
            }
            else if ( s[0] == '>' ) {
                s[0] = '<';
            }
        }

        if ( x == l || x == r ) {
            //std::cerr << " ** at " << gt_fr << " " << gt_to << " " << l << " " << r << " checking " << x << " " << s << " " << y << std::endl;
            if ( s == "<" ) {
                if ( y < gt_fr || y > gt_to ) {
                    return false;   
                }
            }
            else if ( s == "<=" ) {
                if ( y < std::min(gt_fr, l) || y > std::max(gt_to, r) ) {
                    return false;
                }
            }
            else if ( s == "=" ) {
                if ( y != l && y != r ) {
                    return false;
                }
            }
            else if ( s == ">=" ) {
                if ( y >= gt_fr && y <= gt_to ) {
                    return false; 
                }
            }
            else {
                if ( y >= std::min(gt_fr, l) && y <= std::max(gt_to, r) ) {
                    return false;
                }
            }
        }
    }

    return true;
}


Int count ( unsigned l_pos , unsigned r_pos ) {
    Int& answer = dp[l_pos][r_pos];
    if ( seen[l_pos][r_pos] ++ ) {
        return answer;
    }
    
    if ( l_pos + 1 == r_pos ) {
        //std::cerr << "at " << l_pos << " " << r_pos << " answer = " << (check_constraints(MAX_POS, MAX_POS, l_pos, r_pos)) << std::endl;
        return answer = (check_constraints_end(l_pos, r_pos));
    }

    answer = 0;

    // left
    if ( check_constraints(l_pos + 2, r_pos, l_pos, l_pos + 1) ) {
        //std::cerr << "left from " << l_pos << " " << r_pos << " to " << l_pos + 2 << " " << r_pos << std::endl;
        answer += count(l_pos + 2, r_pos);
    }
    // middle
    if ( check_constraints(l_pos + 1, r_pos - 1, l_pos, r_pos) ) {
        //std::cerr << "middle from " << l_pos << " " << r_pos << " to " << l_pos + 1 << " " << r_pos - 1 << std::endl;
        answer += count(l_pos + 1, r_pos - 1);
    }
    // right
    if ( check_constraints(l_pos, r_pos - 2, r_pos - 1, r_pos) ) {
        //std::cerr << "right from " << l_pos << " " << r_pos << " to " << l_pos << " " << r_pos - 2 << std::endl;
        answer += count(l_pos, r_pos - 2);
    }

    //std::cerr << "at " << l_pos << " " << r_pos << " answer = " << answer << std::endl;
    return answer;
}


int main ( void ) {

    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    unsigned k;
    std::cin >> n >> k;

    for ( unsigned i = 0 ; i < k ; ++ i ) {
        unsigned a; std::string s; unsigned b;
        std::cin >> a >> s >> b;
        constraints[i] = std::make_tuple(std::move(a), std::move(s), std::move(b));
    }

    std::cout << count(1, 2*n) << std::endl;

    return 0;
}
