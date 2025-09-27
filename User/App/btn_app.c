#include "btn_app.h"
#include "ebtn.h" 
#include "string.h"

const ebtn_btn_param_t defaul_ebtn_param = EBTN_PARAMS_INIT(
    20,     // time_debounce: 按下稳定 20ms
    20,     // time_debounce_release: 释放稳定 20ms
    50,     // time_click_pressed_min: 最短单击按下 50ms
    500,    // time_click_pressed_max: 最长单击按下 500ms (超过则不算单击)
    50,    // time_click_multi_max: 多次单击最大间隔 300ms (两次点击间隔超过则重新计数)  不需要双击之类的时候改小
    500,    // time_keepalive_period: 长按事件周期 500ms (按下超过 500ms 后，每 500ms 触发一次)
    5       // max_consecutive: 最多支持 5 连击
);

typedef enum
{
    /* 用于单个按键 */
    USER_BUTTON_0 = 0,
    USER_BUTTON_1,
    USER_BUTTON_2,
    USER_BUTTON_3,
    USER_BUTTON_4,
    USER_BUTTON_5,
    USER_BUTTON_MAX,
    /* 用于组合按键，不使用组合按键时可以删除 */
    USER_BUTTON_COMBO_0 = 0x100,
    USER_BUTTON_COMBO_1,
    USER_BUTTON_COMBO_2,
    USER_BUTTON_COMBO_3,
    USER_BUTTON_COMBO_MAX,
} user_button_t;

/* 用于单个按键 */
static ebtn_btn_t btns[] = 
{
    
	EBTN_BUTTON_INIT(USER_BUTTON_0, &defaul_ebtn_param),
	EBTN_BUTTON_INIT(USER_BUTTON_1, &defaul_ebtn_param),
	EBTN_BUTTON_INIT(USER_BUTTON_2, &defaul_ebtn_param),
	EBTN_BUTTON_INIT(USER_BUTTON_3, &defaul_ebtn_param),
	EBTN_BUTTON_INIT(USER_BUTTON_4, &defaul_ebtn_param),
	EBTN_BUTTON_INIT(USER_BUTTON_5, &defaul_ebtn_param),
};
 
///* 用于组合按键，不使用组合按键时可以删除 */
//static ebtn_btn_combo_t btns_combo[] = {
//    EBTN_BUTTON_COMBO_INIT(USER_BUTTON_COMBO_0, &defaul_ebtn_param),
//    EBTN_BUTTON_COMBO_INIT(USER_BUTTON_COMBO_1, &defaul_ebtn_param),
//    EBTN_BUTTON_COMBO_INIT(USER_BUTTON_COMBO_2, &defaul_ebtn_param),
//};

/* 单一按键绑定按键，读取电平 */
uint8_t prv_btn_get_state(struct ebtn_btn *btn)
{
	switch (btn->key_id)
	{
	case USER_BUTTON_0:
		return !HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10);
	case USER_BUTTON_1:
		return !HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11);
	case USER_BUTTON_2:
		return !HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12);
	case USER_BUTTON_3:
		return !HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13);
	case USER_BUTTON_4:
		return !HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14);
	case USER_BUTTON_5:
		return !HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15);
	default:
		// 对于组合键或其他未明确处理的 ID，返回 0
		return 0;
	}	
}

// EBTN_EVT_ONPRESS = 0x00, /*!< 按下事件 - 检测到有效按下时发送 */
// EBTN_EVT_ONRELEASE,      /*!< 释放事件 - 检测到有效释放事件时发送 (从活动到非活动) */
// EBTN_EVT_ONCLICK,        /*!< 单击事件 - 发生有效的按下和释放事件序列时发送 */
// EBTN_EVT_KEEPALIVE,      /*!< 保持活动事件 - 按钮处于活动状态时定期发送 */

void prv_btn_event(struct ebtn_btn *btn, ebtn_evt_t evt)
{
	// 只处理单击/双击事件
	if (evt == EBTN_EVT_ONCLICK)
	{
		uint16_t click_cnt = ebtn_click_get_count(btn);

		switch (btn->key_id)
		{
		// --- 普通按键逻辑 ---
		case USER_BUTTON_0:
			if (click_cnt == 1)
			{

			} // 单击
			break;
		case USER_BUTTON_1:
			if (click_cnt == 1)
			{

			}
			break;
        case USER_BUTTON_2:
			if (click_cnt == 1)
			{

			}
			break;
         case USER_BUTTON_3:
			if (click_cnt == 1)
			{

			}
			break;
		default:
			// 其他按键或未处理的点击次数
			break;
		}
	}
}

void app_ebtn_init(void)
{
	ebtn_init(btns, EBTN_ARRAY_SIZE(btns), NULL, 0, prv_btn_get_state, prv_btn_event);

}

void btn_task(void)
{
	ebtn_process(HAL_GetTick());
}
