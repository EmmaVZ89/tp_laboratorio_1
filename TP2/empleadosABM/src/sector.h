/*
 * sector.h
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */

#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct
{
    int id;
    char descripcion[20];
}eSector;


#endif /* SECTOR_H_ */

/** \brief muestra lista de sectores con su id y descripcion
 *
 * \param sectors[] eSector array de sectores
 * \param len int dimension de array de sectores
 * \return int retorna -1 si hay direccion NULL o dimension invalida, devuelve 0 si no hay errores
 *
 */
int printSectors(eSector sectors[], int len);


/** \brief muestra los campos de un sector
 *
 * \param sector eSector sector a mostrar
 * \return void
 *
 */
void printSector(eSector sector);


/** \brief busca el indice de un sector existente
 *
 * \param id int numero de Id del sector
 * \param sectors[] eSector array de sectores
 * \param len int dimension del array de sectores
 * \return int retorna el numero del indice, si no encuentra el sector retorna -1 (tambien en caso de NULL o dimension invalida)
 *
 */
int findSectorById(int id, eSector sectors[], int len);
