#include <bits/stdc++.h>
#include <bitset>

// t0 5 t1 1 t2 2 t3 3 t4 4 zero 0
#define T0 "0001"
#define T1 "0010"
#define T2 "0011"
#define T3 "0100"
#define T4 "0101"
#define ZERO "0000"


// Assembler: LNKIFHPBECOGJMAD 
#define ADD "1110"  // A
#define ORI "0101"  // H
#define SW "0000"   // L
#define BNEQ "1010" // O
#define OR "1011"   // G
#define ADDI "0111" // B
#define ANDI "0100" // F
#define BEQ "0001"
#define LW "1101"
#define SRL "1100"
#define SUBI "1111"
#define J "0110"
#define AND "1000"
#define SUB "1001"
#define NOR "0010"
#define SLL "0011"

using namespace std;

std::string bin_to_hex(std::string binary)
{
    binary = std::string(binary.length() % 4 ? 4 - binary.length() % 4 : 0, '0') + binary;
    std::unordered_map<std::string, char> hex_dict = {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'}, {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'}, {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'}, {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}};
    std::string hexadecimal;
    for (size_t i = 0; i < binary.length(); i += 4)
    {
        std::string group = binary.substr(i, 4);
        hexadecimal += hex_dict[group];
    }
    return hexadecimal;
}

std::vector<std::string> tokenize(const std::string &str, const char delim)
{
    // Construct a stream from the string
    std::stringstream ss(str);
    std::vector<std::string> out;

    std::string s;
    while (std::getline(ss, s, delim))
    {
        if (!s.empty())
        {
            while (s[s.size() - 1] == ' ' || s[s.size() - 1] == '$')
                s.pop_back();
            while (s[0] == ' ' || s[0] == '$')
                s.erase(0, 1);
            out.push_back(s);
        }
    }
    return out;
}
string decimal_to_binary(int number,bool jump)
{
    if(number==0)
      return "0000";
    int n = (int)(log2(number));

    auto ans = bitset<64>(number).to_string().substr(64 - n - 1);
    if(jump and number!=0)
    {
        while (ans.size() < 8)
    {
        ans.insert(ans.begin(), '0'); 
    }
    }
    while (ans.size() < 4)
    {
        ans.insert(ans.begin(), '0');
    }

   
    return ans;
}

void process_token(std::vector<std::string> &ans, bool &jump,bool& load) {
    //for lw,sw and j statemnet handling
    if (ans.size() == 2) {
        auto temp = tokenize(ans[1], '(');
        temp[1].pop_back();
        ans.pop_back();
        for (auto &t : temp)
            ans.push_back(t);
            load=true;
    } else if (ans.size() == 1) {
        ans.push_back("0");
        jump = true;
    }
}

void reorder_tokens(std::vector<std::string> &ans,bool load) {
    //to fit in mips instruction,desination should be at last position
    if (!ans.empty() && !load) {
        auto dest = ans[0];
        ans.erase(ans.begin());
        ans.push_back(dest);
        
    }
    else if(!ans.empty() && load)
    {
       auto dest=ans[2];
       ans.pop_back();
       ans.insert(ans.begin(),dest);
    }
}

std::pair<std::string, std::string> convert_to_binary_and_hex(const std::string &s, std::map<std::string, std::string> &mp) {
    std::string binary, hex;

    auto ans = tokenize(s, ' ');
    binary += mp[ans[0]] + " ";
    hex += bin_to_hex(mp[ans[0]]);
    ans = tokenize(ans[1], ',');
    bool jump=false,load=false;

    process_token(ans, jump,load);
    if(!jump)
     reorder_tokens(ans,load);


   for (auto &a : ans)
    {

        if (mp.find(a) == mp.end())
        {
            cout << a << endl;
            binary += decimal_to_binary(stoi(a),jump) + " ";
            hex += bin_to_hex(decimal_to_binary(stoi(a),jump));
        }
        else
        {
            binary += mp[a] + " ";
            hex += bin_to_hex(mp[a]);
        }
    }

    return {binary, hex};
}

void map_initialization(map<string, string> &mp)
{

    mp["add"] = ADD;
    mp["ori"] = ORI;
    mp["sw"] = SW;
    mp["bneq"] = BNEQ;
    mp["or"] = OR;
    mp["addi"] = ADDI;
    mp["andi"] = ANDI;
    mp["beq"] = BEQ;
    mp["lw"] = LW;
    mp["srl"] = SRL;
    mp["subi"] = SUBI;
    mp["j"] = J;
    mp["and"] = AND;
    mp["sub"] = SUB;
    mp["nor"] = NOR;
    mp["sll"] = SLL;
    mp["t0"] = T0;
    mp["t1"] = T1;
    mp["t2"] = T2;
    mp["t3"] = T3;
    mp["t4"] = T4;
    mp["zero"] = ZERO;
}

int main()
{
    string line;
    ifstream fin("assembly.txt");
    ofstream fbinary("machine.txt");
    ofstream fhex("hex_file.txt");

    map<string, string> mp;
    map_initialization(mp);

    while (getline(fin, line))
    {
        // lineCount++;
        auto binary_and_hex = convert_to_binary_and_hex(line, mp);
        fbinary << binary_and_hex.first << endl;
        fhex << binary_and_hex.second << endl;
    }
    fin.close();
    fbinary.close();
    fhex.close();

    return 0;
}
