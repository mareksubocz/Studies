import React, {useState} from 'react';
import ToDoList from './ToDoList';
import tasksData from './tasksData';
import Task from './Task';

class App extends React.Component {
  constructor() {
      super()
      this.state = {
          tasks: tasksData
      }
      this.handleChange = this.handleChange.bind(this)
  }
  
  handleChange(id) {
      this.setState(prevState => {
          const updatedTodos = prevState.todos.map(todo => {
              if (todo.id === id) {
                  todo.completed = !todo.completed
              }
              return todo
          })
          return {
              tasks: updatedTodos
          }
      })
  }
  
  render() {
      const todoItems = this.state.todos.map(item => <TodoItem key={item.id} item={item} handleChange={this.handleChange}/>)
      
      return (
          <div className="todo-list">
              {todoItems}
          </div>
      )    
  }
}


function App() {
  const [tasks, setTasks] = useState(0);
  

  function onCheckboxChange(id){
    const updatedTodos = tasks.map(todo => {
      if (todo.id === id) {
          todo.completed = !todo.completed
      }
      return todo
    })
    setTasks(updatedTodos)
  }
  return class extends React.Component {
    constructor(){
      setTasks([{
        id: 1,
        text: "spoko foko",
        completed: "false"
    },
    {
        id: 2,
        text: "oko maroko",
        completed: "false"
    },
    {
        id: 3,
        text: "Domi omi",
        completed: "false"
    }
  ])
    }
    render() {
      const taskItems = tasks.map(task => <Task key={task.id} text = {task.text} zaliczone={task.completed} onCheckboxChange={onCheckboxChange}/>)

      return (
        <div className="App">
          <header className="App-header">
            <h1>Welcome to my To Do list!</h1>
            <ToDoList tasks = {taskItems} onChange={onCheckboxChange}/>
          </header>
        </div>
      );
    }
  }
  
    
  
}

export default App;
