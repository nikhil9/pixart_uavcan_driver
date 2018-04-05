#include <modules/driver_pixart_39xx/driver_pixart_39xx.h>
#include <modules/worker_thread/worker_thread.h>
#include <modules/uavcan_debug/uavcan_debug.h>

#define WT hpwork_thread
WORKER_THREAD_DECLARE_EXTERN(WT)

static struct pixart_instance_s pixart_instan;

static struct worker_thread_timer_task_s pixart_test_task;
static void pixart_task_func(struct worker_thread_timer_task_s* task);

RUN_AFTER(INIT_END) {
	pixart_init(&pixart_instan, 3, BOARD_PAL_LINE_SPI3_FLOW_CS, PIXART_TYPE_3901);
    worker_thread_add_timer_task(&WT, &pixart_test_task, pixart_task_func, NULL, MS2ST(1), true);
}

static void pixart_task_func(struct worker_thread_timer_task_s* task) {
	(void)task;
}
