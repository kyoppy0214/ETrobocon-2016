#include "ev3api.h"
#include "ColorSensor.h"
#include "Clock.h"
//#include "self_2.h"
#include "PidWalker.h"

/* default pid(2.0, 0.05, 0.13, 20.0) */
PidWalker::PidWalker():
    colorSensor(PORT_2), pid(0.5, 0.0, 0.8, 30.0) {//(1.0,0.0,0.3,30.0)
}

void PidWalker::trace() {
    //int count = 0;
    //int x=1;
    /* 両輪のリセット */
    walker.reset();
    
    FILE *fp;
    fp = fopen("speed.txt","w");
    int edge_direction = -1;//エッジの向きによって変更(+->右,-->左)
    int flag_edge = 0;
    while(1) {
        if(ev3_button_is_pressed(BACK_BUTTON)) {
            break;
        }
        if(self_localization.self_localization_near_target_coordinates(20,-100,10,0) == 1 && flag_edge == 0) {
            ev3_speaker_play_tone(NOTE_E5, 20);
            edge_direction = walker.edgeChange();
            flag_edge = 1;
            //count = 0;
        }
        
        /*if(self_localization.self_localization_near_target_coordinates(-60,-30,10,0) == 1){
         
           // x = -1;
        }*/
        pid.pid_calculate(colorSensor.getBrightness());
        turn = (int8_t)pid.pid_get_output();
        walker.run(forward, turn);
        self_localization.self_localization_update(edge_direction);//自己位置のデータ更新
        
        self_localization.self_localization_writing_current_coordinates(fp);
        
       // count++;
        clock.sleep(4); /* 4msec周期起動 */
    }
    fclose(fp);
    walker.reset();
}
