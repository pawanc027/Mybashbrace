#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> braceExpansion(string &expression, int &p)
{
	vector<string>	res;
	vector<string>	parse;
	if(p == expression.length()) return res;
	res.emplace_back("");

	while(p<expression.length()) {
		if(expression[p] == '{') {
			++p;
			vector<string> parsed_inside = braceExpansion(expression, p);
			vector<string> new_res;
			for(auto exp1: res) {
				for(auto exp2: parsed_inside) {
					new_res.emplace_back(exp1+exp2);
				}
			}
			res = new_res;
		} else if(expression[p] == '}') {
			++p;
			parse.insert(parse.end(),res.begin(),res.end());
			return parse;
		} else if(expression[p] == ',') {
			++p;		
			parse.insert(parse.end(),res.begin(),res.end());
			res.clear();
			res.emplace_back("");
		} else {
			for(int i = 0;i<res.size();++i){
				res[i] += expression[p];
			}
			++p;
		}
	}
	parse.insert(parse.end(),res.begin(),res.end());
	return parse;
}

void show_usage(std::string name)
{
	std::cerr << "Usage: " << name  << " args"
		  << std::endl;
}


bool validateInput(const std::string& expression)
{
	stack<char> s;
	size_t cnt = 0;
	for(size_t p=0;p<expression.size();++p) {
		if(!((expression[p] >= 'A' && expression[p] <= 'Z') 
			||(expression[p] >= 'a' && expression[p] <='z')
			||(expression[p] == '{')
			||(expression[p] == '}')
			||(expression[p] == ',')))
		{
			return false;
		}
		else if((expression[p] >= 'A' && expression[p] <= 'Z') 
			   ||(expression[p] >= 'a' && expression[p] <='z'))
		{
			++cnt;
		}
		else if( expression[p] == ',') {
			cnt = 0; //reset the counter
		}

		// Checking for balanced braces 
		if (expression[p] == '{') {
			s.push(expression[p]);
			continue;
		}

		// Check Empty Stack
		if (s.empty() 
		      && ( expression[p] == '}' || expression[p] == ','))
		{
			return false;
		}

		if (expression[p] == '}') {
			s.pop();
		}
	}

	if(s.empty() && cnt != 0)
		return true;;

	return false;
}

int main(int argc, char* const argv[])
{
	std::string expr;
	if( argc == 2) { // Fetching the arguments from the command line
		for(size_t x=1;x<argc;++x)
			expr += argv[x]; 
	}
        else if (std::getline(std::cin, expr)) { // Fetching the arguments from unix pipe
		if (expr.empty()) {
			show_usage(argv[0]);
		        return 1;
		}
	}

	// Validate the input arguments
	if(!validateInput(expr)) {
		return 1;
	}

	int x=0;
	vector<string> res = braceExpansion(expr,x); // Perform brace expansion
	for(const auto& s: res) {
		cout<<s<<" ";
	}
	std::cout<<"\n";
	return 0;
}
