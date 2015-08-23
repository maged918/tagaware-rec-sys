//Language: GNU C++11


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range {
    long long int left;
    long long int right;
};

struct Question {
    int level;
    int answer;
    Range range;
};

bool operator < (const Range &a, const Range &b) {
    if (a.left == b.left) {
        return a.right < b.right;
    }
    return a.left < b.left;
}

bool operator < (const Question &a, const Question &b) {
    if (a.answer==b.answer) {
        return a.range < b.range;
    }
    return a.answer > b.answer;
}

bool rangesIntersection(Range &a, Range &b) { // return false if empty, else result in 1st parameter
    if (b.left > a.right) {
        return false;
    }
    a.left=b.left;
    a.right=min(a.right,b.right);
    return true;
}
// not universal case function, we assume that beginning of range 'a' is exactly before or in last range in vector
bool rangesComplement(vector<Range> &ranges, Range &a) { // return false if empty, else edit vector
    int index=ranges.size()-1;
    if (a.left > ranges[index].left) {
        if (a.right < ranges[index].right) {
            ranges.push_back({a.right+1,ranges[index].right});
        }
        ranges[index].right=min(ranges[index].right,a.left-1);
        return true;
    }
    if (a.right < ranges[index].right) {
        ranges[index].left=max(ranges[index].left,a.right+1);
        return true;
    }
    ranges.pop_back();
    return !ranges.empty();
}

bool mergeRangesOnLevel(vector<Question> &questions, vector<Range> &range) {
    for (int i=0; i<questions.size(); i++) {
        if (questions[i].answer==1) {
            if (!rangesIntersection(range[0],questions[i].range)) {
                return false;
            }
        } else {
            if (!rangesComplement(range,questions[i].range)) {
                return false;
            }
        }
    }
    return true;
}

void expandRangeToNextLevel(Question &question, int h) {
    if (question.level==h) {
        return;
    }
    question.range.left=2*question.range.left;
    question.range.right=2*question.range.right+1;
    question.level++;
    expandRangeToNextLevel(question,h);
}

int main()
{
    int h,q;
    cin >> h >> q;
    vector<Question> questions (q);
    for (int j=0; j<q; j++) {
        int i,a;
        long long int l,p;
        cin >> i >> l >> p >> a;
        questions[j]={i,a,{l,p}};
        expandRangeToNextLevel(questions[j],h);
    }
    sort(questions.begin(),questions.end());
    Question tmp={1,1,1,1};
    expandRangeToNextLevel(tmp,h);
    vector<Range> ranges;
    ranges.push_back(tmp.range);
    if (!mergeRangesOnLevel(questions,ranges)) {
        cout << "Game cheated!" << endl;
        return 0;
    }
    if (ranges.size()>1 || ranges[0].left!=ranges[0].right) {
        cout << "Data not sufficient!" << endl;
        return 0;
    }
    cout << ranges[0].left << endl;
    return 0;
}
