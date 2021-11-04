void Skaitymas (int t, int & m, std::vector<duom>& Duomenys){
    std::string s = std::to_string(t);
    std::ifstream fd("test" + s + ".md");
    if (!fd.good()){
        throw "Failai neegzistuoja";
    }
    int laik;
    std::string pvz;
    std::vector<int> Medv;
    while (!fd.eof()){
        
        int sum = 0, kas = 0;
        Duomenys.push_back(duom());
        getline(fd, pvz);
        std::istringstream in_line(pvz);
        try {
            in_line >> Duomenys[m].var;
            //Patikra (Duomenys[m].var);
            in_line >> Duomenys[m].pav;
            //Patikra (Duomenys[m].pav);
        } catch (const char* msg){
            cout << msg << endl;
        }
        while (in_line >> laik){
            if (laik == 0){
                cout << "Blogai ivesti duomenys pas studenta: " << Duomenys[m].var << ", " << t << "-ame faile" << endl;
                sum = 0;
                break;
            }
            sum = sum + laik;
            Medv.push_back(int());
            Medv[kas] = laik;
            kas++;
        }

        if (Medv.empty()){
            cout << "Blogai ivesti duomenys " << t << "-ame faile" << endl;
            break;
        }
        int egz = Medv[kas-1];
        kas--;
        sum = sum - egz;
        Skaiciavimai (Duomenys, m, kas, Medv, sum, egz);
        m++;
    } 
    fd.close();
}
