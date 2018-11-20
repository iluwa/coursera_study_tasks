#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>
using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

TaskStatus GetNextStatus(const TaskStatus& current_status) {
	return static_cast<TaskStatus>(static_cast<int>(current_status) + 1);
}

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	// Гарантируется вызов только по существующим разработчикам
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return tasks_.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person) {
		if (tasks_.count(person) == 0) {
			tasks_[person] = InitTaskStatus();
		}
		++tasks_[person][TaskStatus::NEW];
	}

	// Обновить статусы по данному количеству задач конкретного разработчика
	// Гарантируется вызов только по существующим разработчикам
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		TasksInfo updated_tasks, untouched_tasks;
		int current_task_count = task_count;
		TaskStatus iterable_status = TaskStatus::NEW;
		while (iterable_status < TaskStatus::DONE) {
			if (tasks_[person][iterable_status] >= current_task_count) {
				updated_tasks[GetNextStatus(iterable_status)] = current_task_count;
				untouched_tasks[iterable_status] = tasks_[person][iterable_status] - current_task_count;
				current_task_count = 0;
			} else {
				updated_tasks[GetNextStatus(iterable_status)] = tasks_[person][iterable_status];
				current_task_count = task_count -  tasks_[person][iterable_status];
				if (current_task_count <= 0) {
					break;
				}
			}
			iterable_status = GetNextStatus(iterable_status);
		}
		for (auto & item : tasks_[person]) {
			item.second = untouched_tasks[item.first] + updated_tasks[item.first];
		}
		return make_tuple(updated_tasks, untouched_tasks);
	}
private:
	map<string, TasksInfo> tasks_;

	map<TaskStatus, int> InitTaskStatus() {
		return {
				{TaskStatus::NEW, 0},
				{TaskStatus::IN_PROGRESS, 0},
				{TaskStatus::TESTING, 0},
				{TaskStatus::DONE, 0}
		};
	}
};

int main() {
	TeamTasks tasks;
	tasks.AddNewTask("Ilia");
	for (int i = 0; i < 3; ++i) {
		tasks.AddNewTask("Ivan");
	}
	cout << "Ilia's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

	TasksInfo updated_tasks, untouched_tasks;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 5);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
	cout << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
	cout << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 7);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
	cout << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Vasya", 7);
	cout << "Updated Vasya's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Vasya's tasks: ";
	PrintTasksInfo(untouched_tasks);

	return 0;
}
