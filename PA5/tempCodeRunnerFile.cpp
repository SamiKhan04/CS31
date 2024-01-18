        if (isspace(line[i]) && i+1 < n && line[lengthL+1] == '\n') {
            line[i] = '\n';
            // outfile << line[i];
            continue;
        }