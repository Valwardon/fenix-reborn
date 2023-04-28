#ifndef CONFIG_H
#define CONFIG_H

// Default configuration values
#define DEFAULT_THRESHOLD 50
#define DEFAULT_RECORDING_DURATION 10

// Global configuration variables
extern int threshold;
extern int recording_duration;

// Function declarations
int load_config(void);
void save_config(void);

#endif /* CONFIG_H */
