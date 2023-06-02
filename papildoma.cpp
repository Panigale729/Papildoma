#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <set>

//deklaracijos

std::set<std::string> extractDomains(const std::string& filename); //is wikipedia svetaines isrenkam domenus
std::set<std::string> findURLs(const std::string& filename, const std::set<std::string>& domainNames);  //ieskom svetainiu



int main()
{

    std::set<std::string> domainNames = extractDomains("domains.txt"); //is wikipedia svetaines (nukopijuotas tekstas i faila) isrenkam domenus

    /* Patikrinam domenus jeigu norim
    std::ofstream outputDomenai("isrinkti_domenai.txt"); //isvedam i si faila
    for (const auto& domain : domainNames) {
        outputDomenai << domain << "\n";
    }
    */
   
    std::set<std::string> URLs = findURLs("tekstas.txt", domainNames);


    for (const auto& url : URLs) {
        std::cout << url << "\n";
    }

    //atidarom faila
    std::ifstream file("tekstas.txt");
    if (!file) {
        std::cerr << "Nepavyko atidaryti failo\n";
        return 1;
    }


    //analizuojam faila
    std::map<std::string, int> wordCount;   //map`as zodziams ir ju pasikartojimo dazniui
    std::map<std::string, std::vector<int>> wordLines;  //mapams zodziams ir ju vietai (eilutems)

    std::string line;   //stringas eilutems teksto
    std::regex wordRegex("[a-zA-Z]+");   // Regex zodziams. Skliausteliuose parodyta, jog tik raides.
    int line_number = 0; //Sekam eilutes numeri


    //imam po eilute is tekstinio failo
    while (std::getline(file, line)) {
        line_number++; //padidinam eilutes numeri
        std::transform(line.begin(), line.end(), line.begin(), ::tolower); // eilute paverciam i mazasias raides

        //naudojam regex zodziu radimui (pirmam ir paskutiniam)
        auto wordsBegin = std::sregex_iterator(line.begin(), line.end(), wordRegex);
        auto wordsEnd = std::sregex_iterator();

        //kiekvienam zodziui eilutei
        for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
            std::smatch match = *i; //dereferincam iteratoriu, kad gautume zodi!
            std::string matchStr = match.str(); //konvertuojam i stringa
            wordCount[matchStr]++; // padidinam zodziu skaiciu. Jeigu egzistuoja zodis, padidinam dazni. Jeigu neegzistuoja, tai pridedam zodi ir jo daznis bus 1.
            wordLines[matchStr].push_back(line_number); // sitam zodziui pridedam eilutes numeri
        }
    }


    //isvedam rezultatas
    std::ofstream outputFile("output.txt"); //isvedam i si faila

    //kiekvienaai porai map`e
    for (const auto& pair : wordCount) {
        if (pair.second > 1) {  //ziurim, ar zodis atsirado bent daugiau negu viena karta
            outputFile << pair.first << ": " << pair.second << " (eilutes: ";    //tada isvedam ta zodi ir jo pasikartojimo dazni

            // Pridedam eiluciu numerius kiekvienam zodziui
            // wordLines[pair.first] duoda vektoriu eiluciu numeriu siam zodziui.
            for (int line : wordLines[pair.first]) {
                outputFile << line << " ";
            }
            outputFile << ")\n";
        }
    }

    outputFile.close(); //uzdarom isvesties faila

    return 0;
}



//is wikepedia failo, kur visi domenai - isskiriam tik domenus.
//labai panasu i main funkcijos veikima
std::set<std::string> extractDomains(const std::string& filename) {
    std::set<std::string> domains;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Nepavyko atidaryti wikepedia domenu failo: " << filename << "\n";
        return domains; // grazinam tuscia set`a
    }

    std::string line;
    std::regex domainRegex("\\.([a-z]+)"); // domenai prasideda tasku

    while (std::getline(file, line)) {
        auto domainsBegin = std::sregex_iterator(line.begin(), line.end(), domainRegex);
        auto domainsEnd = std::sregex_iterator();

        for (std::sregex_iterator i = domainsBegin; i != domainsEnd; ++i) {
            std::smatch match = *i;
            std::string matchStr = match.str();
            domains.insert(matchStr); // pridedam i seta
            //domains.insert(matchStr.substr(1)); // pasalinam taska pradini
        }
    }

    return domains;
}



std::set<std::string> findURLs(const std::string& filename, const std::set<std::string>& domainNames) {
    std::set<std::string> URLs;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Nepavyko atidaryti teksto failo: " << filename << "\n";
        return URLs; // Return an empty set
    }

    std::string line;
    std::regex urlRegex(R"(\b([\w.:/]+\.[a-zA-Z]{2,})\b)");
    std::regex domainRegex(R"(\.([a-zA-Z]{2,})\b)"); // domenas URL`e

    while (std::getline(file, line)) {
        std::smatch match;
        std::smatch domainMatch; // domeno sutapimas

        while (std::regex_search(line, match, urlRegex)) {
            std::string url = match.str();

            if (std::regex_search(url, domainMatch, domainRegex)) {
                std::string domain = domainMatch.str();

                // pridedam tik tada svetaine, jeigu sutampa jos domenas
                if (domainNames.find(domain) != domainNames.end()) {
                    URLs.insert(url);
                }
            }

            line = match.suffix(); // likusi eilute dalis
        }
    }

    return URLs;
}


