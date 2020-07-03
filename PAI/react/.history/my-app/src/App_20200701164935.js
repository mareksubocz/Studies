import React, {useState} from 'react';
import ToDoList from './ToDoList';
import tasksData from './tasksData';
import Task from './Task';



function App() {

  const tasksData = [{
    id: 1,
    text: "spoko foko",
    completed: false
},
{
    id: 2,
    text: "oko maroko",
    completed: false
},
{
    id: 3,
    text: "Domi omi",
    completed: false
}
]

  const [tasks, setTasks] = useState(
    tasksData.map(task => 
      <Task key={task.id} text = {task.text} zaliczone={task.completed} onCheckboxChange={onCheckboxChange}/>
    )
  );

  function onCheckboxChange(id){
    const updatedTodos = tasksData.map(todo => {
      if (todo.id === id) {
          todo.completed = !todo.completed
      }
      return todo
    })
    tasksData = updatedTodos
    setTasks(tasksData.map(task => 
      <Task key={task.id} text = {task.text} zaliczone={task.completed} onCheckboxChange={onCheckboxChange}/>
    ))
  }

  return (
    <div className="App">
      <header className="App-header">
        <h1>Welcome to my To Do list!</h1>
        <ToDoList tasks = {tasks} onChange={onCheckboxChange}/>
      </header>
    </div>
  );
  
}

export default App;
