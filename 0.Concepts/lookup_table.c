/**
 * This is kind of a self notebook about lookup tables. It is part of the
 * material I found in embeddedgurus.com, an article called "A tutorial on
 * lookup tables in C" by Nigel Jones.
 * 
 * @author Adrian Martinez
 */

uint8_t pec_Update(uint8_t pec) {
    
    static const __flash uint8_t lookup[3] = {
        0x00u,  0x07u, 0x0EU

        // This have more values in the original version 
        // but lets keep this notebook simple.
    };

    pec = lookup[pec];
    return pec;
}

/**
 * The use of static: to not allocate the table on the stack every time.
 * 
 * The use of const: this kind of table is used to read data. That means that
 *                   we are not going to modify it's content.
 * 
 * The use of __flash: to tell the compiler that this part of the code is going
 *                     to the flash memory, not into the RAM.
 * /