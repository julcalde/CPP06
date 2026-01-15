To fix:

1. ex00:    - Convert argv[1] to the respective values instead
            of storing into and converting from a double variable.
            something like:
        "   double doubleValue = value.getValue<double>();
            if (doubleValue > static_cast<double>(std::numeric_limits<int>::max()) || doubleValue < static_cast<double>(std::numeric_limits<int>::min())) {
                std::cout << "impossible" << std::endl;
                return;
            }
        "   ref from Peu77
        
            - Add the uppercase 'F' for float values.
