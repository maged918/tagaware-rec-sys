//Language: GNU C++11


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <cstdio>


class TreeRequestSolver
{
public:
    TreeRequestSolver(const std::vector<std::size_t>& parents, std::string data) :
            vertices(data),
            time_in(data.length()),
            time_out(data.length()),
            tree(data.length()),
            vertices_at_deep(data.length()),
            encoded_symbols(26),
            last_prefix_on_deep(data.length()),
            count_odd_symbols_on_prefix(data.length())
    {
        initialize_encoded_symbols();
        create_tree(parents);
    }

    bool request(std::size_t root, std::size_t h)
    {
        --root;
        --h;


//        auto left = std::lower_bound(std::begin(vertices_at_deep.at(h)), std::end(vertices_at_deep.at(h)),
//                                     time_in.at(root),
//                                     [this](std::size_t v, std::size_t time)
//                                     {
//                                         return time_in.at(v) < time;
//                                     });

        auto left = std::lower_bound(std::begin(vertices_at_deep[h]), std::end(vertices_at_deep[h]),
                                     time_in[root],
                                     [this](std::size_t v, std::size_t time)
                                     {
                                         return time_in[v] < time;
                                     });

//        auto right = std::upper_bound(std::begin(vertices_at_deep.at(h)), std::end(vertices_at_deep.at(h)),
//                                      time_out.at(root),
//                                      [this](std::size_t time, std::size_t v)
//                                      {
//                                          return time < time_out.at(v);
//                                      });
        auto right = std::upper_bound(std::begin(vertices_at_deep[h]), std::end(vertices_at_deep[h]),
                                      time_out[root],
                                      [this](std::size_t time, std::size_t v)
                                      {
                                          return time < time_out[v];
                                      });

        if(std::distance(left, right) > 0)
        {
//            auto left_prefix = count_odd_symbols_on_prefix.at(*left);
            auto left_prefix = count_odd_symbols_on_prefix[*left];
//            auto right_prefix = count_odd_symbols_on_prefix.at(*std::prev(right));
            auto right_prefix = count_odd_symbols_on_prefix[*std::prev(right)];

            auto count = left_prefix ^right_prefix;
//            count = encode_symbol_and_add_to_counted(vertices.at(*left), count);
            count = encode_symbol_and_add_to_counted(vertices[*left], count);

            return !(count & (count - 1));
        }
        else
        {
            return true;
        }
    }

private:
    void create_tree(const std::vector<std::size_t>& parents)
    {
        for(std::size_t i = 0; i < parents.size(); ++i)
        {
//            tree.at(parents.at(i) - 1).insert(i + 1);
            tree[parents[i] - 1].insert(i + 1);
        }

        run_dfs();
    }

    void run_dfs()
    {
        std::size_t time = 0;
        dfs(0, time);
    }

    void dfs(std::size_t vertex, std::size_t& time, std::size_t deep = 0)
    {
//        time_in.at(vertex) = time++;
        time_in[vertex] = time++;

//        last_prefix_on_deep.at(deep) = encode_symbol_and_add_to_counted(vertices.at(vertex),
//                                                                        last_prefix_on_deep.at(deep));
        last_prefix_on_deep[deep] = encode_symbol_and_add_to_counted(vertices[vertex], last_prefix_on_deep[deep]);
//        count_odd_symbols_on_prefix.at(vertex) = last_prefix_on_deep.at(deep);
        count_odd_symbols_on_prefix[vertex] = last_prefix_on_deep[deep];
//        vertices_at_deep.at(deep).push_back(vertex);
        vertices_at_deep[deep].push_back(vertex);

        for(const auto& child: tree[vertex])
        {
            dfs(child, time, deep + 1);
        }

//        time_out.at(vertex) = time++;
        time_out[vertex] = time++;
    }

    void initialize_encoded_symbols()
    {
        for(std::size_t i = 0; i < 26; ++i)
        {
//            encoded_symbols.at(i) = (unsigned long)(1 << i);
            encoded_symbols[i] = (unsigned long)(1 << i);
        }
    }

    std::size_t encode_symbol(char c)
    {
//        return encoded_symbols.at((unsigned long)(c - 'a'));
        return encoded_symbols[(unsigned long)(c - 'a')];
    }

    std::size_t encode_symbol_and_add_to_counted(char c, std::size_t counted)
    {
        return counted ^ encode_symbol(c);
    }

private:
    std::string vertices;
    std::vector<std::size_t> time_in;
    std::vector<std::size_t> time_out;
    std::vector<std::unordered_set<std::size_t>> tree;
    std::vector<std::vector<std::size_t>> vertices_at_deep;
    std::vector<std::size_t> encoded_symbols;
    std::vector<std::size_t> last_prefix_on_deep;
    std::vector<std::size_t> count_odd_symbols_on_prefix;
};


int main()
{
    std::cin.sync_with_stdio(false);

    std::size_t n, m;
    std::cin >> n >> m;

    std::vector<std::size_t> parents(n - 1);
    for(auto& p: parents)
    {
        std::cin >> p;
    }

    std::string s;
    std::cin >> s;

    TreeRequestSolver solver(parents, s);

    for(std::size_t i = 0; i < m; ++i)
    {
        std::size_t v, h;
        std::cin >> v >> h;

        if(solver.request(v, h))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}