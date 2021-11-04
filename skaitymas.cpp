void skaitymas (int file_nr, int & m, std::vector<duom>& Duomenys){
    std::string stud_nr = std::to_string(t);
    std::ifstream fd("test" + stud_nr + ".md");
    if (!fd.good()){
        throw "Failai neegzistuoja";
    }
    int laik;
    std::string first_line;
    std::vector<int> median_vector;
    while (!fd.eof()){
        
        int sum = 0, kas = 0;
        Duomenys.push_back(duom());
        getline(fd, first_line);
        std::istringstream in_line(first_line);
        try {
            in_line >> Duomenys[m].var;
            in_line >> Duomenys[m].pav;
        } catch (const char* msg){
            cout << msg << endl;
        }
        while (in_line >> laik){
            if (laik == 0){
                cout << "Blogai ivesti duomenys pas studenta: " << Duomenys[m].var << ", " << file_nr << "-ame faile" << endl;
                sum = 0;
                break;
            }
            sum = sum + laik;
            median_vector.push_back(int());
            median_vector[kas] = laik;
            kas++;
        }

        if (median_vector.empty()){
            cout << "Blogai ivesti duomenys " << file_nr << "-ame faile" << endl;
            break;
        }
        int egz = median_vector[kas-1];
        kas--;
        sum = sum - egz;
        Skaiciavimai (Duomenys, m, kas, median_vector, sum, egz);
        m++;
    } 
    fd.close();
}
