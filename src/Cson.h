#include "arduinoFFT.h"
#include <driver/i2s.h>
#include <stdint.h>
#include "esp_err.h"
# include <stddef.h>

#define SAMPLES 512 // Nombre d'échantillons
#define SAMPLING_FREQUENCY 44100 // Fréquence d'échantillonnage
#define DMA_BUF_LEN 512 // Taille du buffer DMA : 512 échantillons
#define DMA_BUF_COUNT 8 // Nombre de buffers DMA : 8

class Cson {
    public:
    /// @brief niveau sonore moyenne
    float niveauSonoreMoyen;
  /// @brief niveau sonore crete a crete
  float niveauSonoreCrete;

  private:
  /// @brief niveau sonore reel
  float vReal;
  /// @brief niveau sonore imaginaire
  float vImag;
  /// @brief nomvre d'octet lors de l'aquisition DNA
  size_t bytesRead;
  /// @brief pointeur  I2S brute
  int32_t* i2sData;
  
  public:
  /// @brief consturteur de la basse 
  Cson();
  /// @brief configur le periherique i2s  pour l'aquisition sonore 
  /// @return une erreur si non 
  esp_err_t Setup();
  /// @brief aquisition d'échantillon de DNA
  /// @return si c'est ok, sinon false
  esp_err_t SamplesDmaAcquisition();

};