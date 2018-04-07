#include <modules/driver_pixart_39xx/driver_pixart_39xx.h>
#include <modules/worker_thread/worker_thread.h>
#include <modules/uavcan_debug/uavcan_debug.h>

#define WT hpwork_thread
WORKER_THREAD_DECLARE_EXTERN(WT)

static struct pixart_instance_s pixart_instance;
struct pixart_motion_burst_s motion_burst;

static struct worker_thread_timer_task_s pixart_test_task;
static void pixart_task_func(struct worker_thread_timer_task_s* task);

RUN_AFTER(INIT_END) {
	pixart_init(&pixart_instance, 3, BOARD_PAL_LINE_SPI3_FLOW_CS, PIXART_TYPE_3901);
    worker_thread_add_timer_task(&WT, &pixart_test_task, pixart_task_func, NULL, MS2ST(1000), true);
}

static void pixart_task_func(struct worker_thread_timer_task_s* task) {
	(void)task;

	pixart_read_motion_burst(&pixart_instance, &motion_burst);
	uavcan_send_debug_keyvalue("motion", motion_burst.motion);
	uavcan_send_debug_keyvalue("observation", motion_burst.observation);
	uavcan_send_debug_keyvalue("delta_x", motion_burst.delta_x);
	uavcan_send_debug_keyvalue("delta_y", motion_burst.delta_y);
	uavcan_send_debug_keyvalue("sqaul", motion_burst.squal);
	uavcan_send_debug_keyvalue("rawdata_sum", motion_burst.rawdata_sum);
	uavcan_send_debug_keyvalue("max_raw", motion_burst.max_raw);
	uavcan_send_debug_keyvalue("min_raw", motion_burst.min_raw);
	uavcan_send_debug_keyvalue("shutter_upper", motion_burst.shutter_upper);
	uavcan_send_debug_keyvalue("shutter_lower", motion_burst.shutter_lower);

}
