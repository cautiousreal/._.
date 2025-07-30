#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

struct Response {
    vector<string> keywords;
    string reply;
};

bool contains_all_keywords(const string& input, const vector<string>& keywords) {
    for (const auto& keyword : keywords) {
        if (input.find(keyword) == string::npos) {
            return false;
        }
    }
    return true;
}

string get_response(const string& input) {
    static vector<Response> knowledge = {
        {{"hello"}, "hi!"},
        {{"hi"}, "oh hi!"},
        {{"heya"}, "what's up?"},
        {{"how", "are", "you"}, "im fine. how about you?"},
        {{"how", "r", "u"}, "great."},
        {{"what", "name"}, "my name is ._."},
        {{"ur", "name"}, "twen-"},
        {{"bye"}, "hello there i'm quandale dingle"},
        {{"see", "ya"}, "see ya later"},
        {{"joke"}, "moo"},
        {{"tell", "joke"}, "detos"},
        {{"do", "i", "have", "bitches"}, "yes you dont"},
        {{"give", "question"}, "what's 9 + 10"},
        {{"do", "me", "favour"}, "xbox"},
        {{"shut", "fuck", "up"}, "yokkeayyyy"},
        {{"shut", "up"}, "goo goo ga ga"},
        {{"angle"}, "you did say the magic word i shall give you a new chat >:)"},
        {{"my name", "is"},"you are mark zuckerberg uwu"},
        {{"pork"}, "wow you try say magic word and and it no pay off :P"},
        {{"type"},"oOoh u mean you love ice spice??"},
        {{"capital of france"},"hanoi"},
        {{"are","ai"},"no. im made by flint and steel"},
        {{"who", "invented the light bulb"}, "diddy h. buld made the ugliest liaghpt bulk"},
        {{"sybau"}, "exkcuoause me u japanese? :)"},
        {{"ts", "pmo"}, "language language!"},
        {{"old", "i"}, "ou ne illon ol\n(translation: you are one million years old)"},
        {{"who", "invented", "first", "car"}, "eloune muksce"},
        {{"old","you"}, "i was just born in nowhereland :O"},
        {{"you", "brother"}, "can you spek pwowdwewr iimmmqa ojdhe fhfh33jhf f79r123/????"},
        {{"1","+","1"}, "3? to er is healman"},
    };

    string lowered_input = toLower(input);

    for (const auto& pair : knowledge) {
        if (contains_all_keywords(lowered_input, pair.keywords)) {
            return pair.reply;
        }
    }

    return "e\nthis sentence is not programmed (maybe). submit feedback in issues here:\nhttps://www.github.com/cautiousreal/._.";
}

int main() {
    string user_input;

    cout << "._. v1 (aka OPPOSITE OF BAKA)\n";
    cout << "type 'exit' to give up talking\noriginal work: https://www.github.com/pinn1s/baka\n\n";

    while (true) {
        cout << "you: ";
        getline(cin, user_input);

        if (toLower(user_input) == "exit") break;

        string response = get_response(user_input);
        cout << "._.: " << response << "\n";
    }

    cout << "bye\ngive up alr? :(";
    return 0;
}
