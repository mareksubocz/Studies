import React from 'react';
import ToDoList from './ToDoList';



function App() {

  const [tasks, setTasks] = useState(0);

  tasks = [
    {
      id: 1,
      text: "spoko foko"
    },
    {
      id: 2,
      text: "oko maroko"
    },
    {
      id: 3,
      text: "Domi omi"
    }
  ]

  function onCheckboxChange(id){

  }



  return (
    <div className="App">
      <header className="App-header">
        <h1>Welcome to my To Do list!</h1>
        <ToDoList tasks = {tasks} />
      </header>
    </div>
  );
}

export default App;
