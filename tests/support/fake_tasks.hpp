#ifndef FAKE_TASKS_HPP_5DF011EA55614771AC70289249DFEE44
#define FAKE_TASKS_HPP_5DF011EA55614771AC70289249DFEE44

#include "task_tracking.hpp"

class SimpleTask;
inline ITaskLogger &operator<<(ITaskLogger &logger, SimpleTask *task);

class SimpleTask {
  public:
    SimpleTask(int id, ITaskLogger &log) : call_count(0), id_(id), log_(log) {}
    void action() {
        call_count++;
        log_ << this;
    }
    int call_count;
    int id_;
    ITaskLogger &log_;
    static void externAct(void *me) { static_cast<SimpleTask *>(me)->action(); }
};

inline ITaskLogger &operator<<(ITaskLogger &logger, SimpleTask *task) {
    logger.log(task->id_, task->call_count);
    return logger;
}

#endif