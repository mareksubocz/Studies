import React, {useState} from 'react';
import ToDoList from './ToDoList';
import tasksData from './tasksData';



function App() {

  const [tasks, setTasks] = useState(0);

  setTasks(tasksData.map(task => <Task key={task.id} text = {task.text} zaliczone={task.zaliczone} onCheckboxChange={onCheckboxChange}/>))

  function onCheckboxChange(id){
    const updatedTodos = tasks.map(todo => {
      if (todo.id === id) {
          todo.completed = !todo.completed
      }
      return todo
    })
    setTasks(updatedTodos)
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
