import React, {useState} from 'react';
import ToDoList from './ToDoList';
import tasksData from './tasksData';
import Task from './Task';



function App() {

  const [tasks, setTasks] = useState(tasksData)
  const [filter, setFilter] = useState(false)

  function onCheckboxChange(id){
    const updatedTodos = tasksData.map(todo => {
      if (todo.id === id) {
          todo.completed = !todo.completed
      }
      return todo
    })
    setTasks(updatedTodos)
  }

  function onFilterChange(){
    setFilter(!filter)
  }

  function onNewTask(text){
    alert(text)
  }

  return (
    <div className="App">
      <header className="App-header">
        <h1>Welcome to my To Do list!</h1>
        <ToDoList 
        tasks = {
          tasks.map(task => <Task id={task.id} text={task.text} zaliczone={task.completed} onCheckboxChange={onCheckboxChange} filter={filter}/>)
        }
        onFilterChange={onFilterChange}
        filtered={filter}/>
      </header>
    </div>
  );
  
}

export default App;
