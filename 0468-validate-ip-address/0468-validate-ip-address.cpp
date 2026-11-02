class Solution {
public:
    string validIPAddress(string queryIP) {

        // IPv4
        if (queryIP.find('.') != string::npos) {

            vector<string> parts;
            string temp = "";

            for (char c : queryIP) {
                if (c == '.') {
                    parts.push_back(temp);
                    temp = "";
                } 
                else {
                    temp += c;
                }
            }

            parts.push_back(temp);

            if (parts.size() != 4)
                return "Neither";

            for (string part : parts) {

                if (part.empty() || part.size() > 3)
                    return "Neither";

                if (part.size() > 1 && part[0] == '0')
                    return "Neither";

                int num = 0;

                for (char c : part) {
                    if (c < '0' || c > '9')
                        return "Neither";

                    num = num * 10 + (c - '0');
                }

                if (num > 255)
                    return "Neither";
            }

            return "IPv4";
        }

        // IPv6
        if (queryIP.find(':') != string::npos) {

            vector<string> parts;
            string temp = "";

            for (char c : queryIP) {
                if (c == ':') {
                    parts.push_back(temp);
                    temp = "";
                } 
                else {
                    temp += c;
                }
            }

            parts.push_back(temp);

            if (parts.size() != 8)
                return "Neither";

            for (string part : parts) {

                if (part.empty() || part.size() > 4)
                    return "Neither";

                for (char c : part) {

                    if (!isdigit(c) &&
                        !(c >= 'a' && c <= 'f') &&
                        !(c >= 'A' && c <= 'F')) {
                        return "Neither";
                    }
                }
            }

            return "IPv6";
        }

        return "Neither";
    }
};