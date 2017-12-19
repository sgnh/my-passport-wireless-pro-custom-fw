#ifndef __CUSTOMIZED_H_
#define __CUSTOMIZED_H_	

#define EXECUTE_CUSTOMIZED_FUNCTION	  	env_handler_customized("set Let env");
#define EXECUTE_CUSTOMIZED_FUNCTION_1 	({int __ret=0; __ret = detect_recovery_flag("Check Let Recovery"); __ret; })
						
										
void env_handler_customized(char *str);
int detect_recovery_flag(char *str);






#endif	/* __CUSTOMIZED_H_ */
