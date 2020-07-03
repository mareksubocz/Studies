import React, {useState} from 'react';
import ToDoList from './ToDoList';



function App() {

  const [tasks, setTasks] = useState(0);

  // setTasks([
  //   {
  //     id: 1,
  //     text: "spoko foko",
  //     completed: "false"
  //   },
  //   {
  //     id: 2,
  //     text: "oko maroko",
  //     completed: "false"
  //   },
  //   {
  //     id: 3,
  //     text: "Domi omi",
  //     completed: "false"
  //   }
  // ])

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
