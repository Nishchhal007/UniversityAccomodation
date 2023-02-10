
            s_var = 0;
            file2.read((char *)&temp, sizeof(temp));

            while (!file2.eof())
            {
                if (n.compare(temp.get_hostel()) == 0)
                {
                    temp.set_mess_bill(0);
                }
                file2.seekp(sizeof(temp) * s_var);
                file2.write((char *)&temp, sizeof(temp));

                file2.read((char *)&temp, sizeof(temp));
                s_var++;
            }
            cout << "Reset ";