//
//  main.cpp
//  [Algorithm]Sorting
//
//  Created by 장형원 on 2016. 4. 8..
//  Copyright © 2016년 jhw. All rights reserved.
//

#include <iostream>

void usage()
{
    std::cerr << "Usage : sort <input-file> <output-file>" << std::endl;
}

int main(int argc, const char * argv[]) {
    
    if(argc != 3)
    {
        usage();
        exit(EXIT_FAILURE);
    }
    
    FILE *ifp = fopen(argv[2], "w");
    if(!ifp)
    {
        std::cerr << "Cannot open input file" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    
    
    
    
    
    
    
    
    
    fclose(ifp);
    
    return 0;
}
